/* Copyright (C) 2021 Matteo Foglieni

This file is part of Bonnor-Ebert.

Bonnor-Ebert is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Bonnor-Ebert is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Bonnor-Ebert.  If not, see <https://www.gnu.org/licenses/>. */


#include "VettoreLineare.hpp"
#include "Vettore.hpp"
#include "FunzioneVettoriale.hpp"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

#include "argh.h"

#define pi 3.141592653589

using namespace std;

#define USAGE \
	programName << ": a C++ tool to solve the Bonnor-Ebert equation." << endl << endl << \
	"Usage: " << programName << " [options]" << endl << endl << \
	"Usage: " << endl << \
	programName << " -h|--help" << endl << \
	programName << " euler [options]" << endl << \
	programName << " rungekutta [options]" << endl << endl << \
	"Run '" << programName << " <action-name> -h|--help' for all supported options." << endl

#define HELP_EULERO \
	"euler: solve the Bonnor-Ebert equation using Euler method." << endl << endl << \
	"Usage: " << programName << " euler [options]" << endl << endl << \
	"Available options:" << endl << \
	"	-h, --help				Print this message." << endl << \
	"	-s <step>, --step=<step>		Step measure to be used solving the differential equation."  << endl << \
	"	-b <begin>, --begin=<begin>	Beginning value of csi, where the algothims starts." << endl << \
	"	-e <end>, --end=<end>		Ending value of csi, where the algorithm ends." << endl << \
	"	-c <cut>, --cut=<cut>		Csi value at which we wants to cut the Bonnor-Ebert sphere." << endl

#define HELP_RUNGEKUTTA \
	"rungekutta: solve the Bonnor-Ebert equation using Runge-Kutta method." << endl << endl << \
	"Usage: " << programName << " rungekutta [options]" << endl << endl << \
	"Available options:" << endl << \
	"	-h, --help				Print this message." << endl << \
	"	-s <step>, --step=<step>		Step measure to be used solving the differential equation."  << endl << \
	"	-b <begin>, --begin=<begin>	Beginning value of csi, where the algothims starts." << endl << \
	"	-e <end>, --end=<end>		Ending value of csi, where the algorithm ends." << endl << \
	"	-c <cut>, --cut=<cut>		Csi value at which we wants to cut the Bonnor-Ebert sphere." << endl

int eulero(argh::parser cmdl);
int rungekutta(argh::parser cmdl);

//void assert_close(double ,double );
//void test_program(VettoreLineare , Eulero , OscillatoreArmonico* );
int main(int argc, char *argv[]){
	argh::parser cmdl;

	cmdl.add_params({
			 "-s", "--step",
			 "-b", "--begin",
			 "-e", "--end",
			 "-c", "--cut",
			 });

	cmdl.parse(argc, argv);
	const string programName = cmdl[0];
	const string actionName = cmdl[1];

	if (actionName == "Euler") { 
		return eulero(cmdl);
	} else if (actionName == "RK") {
		return rungekutta(cmdl);
	} else if (cmdl[{"-h", "--help"}]) {
		cout << USAGE;
		return 0;
	} else {
		cout << USAGE;
		return 1;
	}

	//test_program(x,myEuler,LE);
}

int eulero(argh::parser cmdl){
	const string programName = cmdl[0];
	const string actionName = cmdl[1];

	if (cmdl[{"-h", "--help"}]) {
		cout << HELP_EULERO;
		return 0;
	}

	double h, csi_begin, csi_end, csi_cut;
	cmdl({"-s", "--step"}, 0.001) >> h;
	cmdl({"-b", "--begin"}, 0.0001) >> csi_begin;
	cmdl({"-e", "--end"}, 5) >> csi_end;
	cmdl({"-c", "--cut"}, 4) >> csi_cut;

	if(csi_begin<=0.0){
		cout << "The input value of csi_begin=" << csi_begin << 
			" must be >=0="<< endl;
		return 1;
	}else if (csi_begin > csi_end){
		cout << "The input value of csi_begin=" << csi_begin << 
			" must be < than csi_end="<< csi_end << endl;
		return 1;
	}else if (csi_cut > csi_end){
		cout << "The input value of csi_cut=" << csi_cut << 
			" must be <= than csi_end="<< csi_end << endl;
		return 1;
	}else if(csi_cut < csi_begin){
		cout << "The input value of csi_cut=" << csi_cut << 
			" must be >= than csi_begin="<< csi_begin << endl;
		return 1;
	}else if(h > 0.3*(csi_end-csi_begin)){
		cout << "The input value of the step=" << h << 
			" must be <= than 0.3*(csi_end-csi_begin)="<< 
			0.3*(csi_end-csi_begin) << endl;
		return 1;
	}

	Eulero myEuler;
	BonnorEbert* BE = new BonnorEbert();
	int nstep = int(csi_end/h + 0.5);
	VettoreLineare x(2);
	x.setComponent(0, 0.);
	x.setComponent(1, 0.);

	ofstream uscita_Eulero;
	uscita_Eulero.open("Bonnor-Ebert_Eulero.dat");

	double csi = csi_begin;
	for(int i=0; i<nstep; i++){
		uscita_Eulero << i << "\t "  << csi << "\t " << x.getComponent(0) << endl;
		//uscita_RK << i << "\t "  << csi << "\t " << x.getComponent(0) << endl;
		x = myEuler.Passo(BE, x, h, csi);
		csi += h;
	}

	uscita_Eulero.close();
	uscita_Eulero.clear();
	return 0;
}

int rungekutta(argh::parser cmdl){
	const string programName = cmdl[0];
	const string actionName = cmdl[1];

	if (cmdl[{"-h", "--help"}]) {
		cout << HELP_RUNGEKUTTA;
		return 0;
	}

	double h, csi_begin, csi_end, csi_cut;
	cmdl({"-s", "--step"}, 0.001) >> h;
	cmdl({"-b", "--begin"}, 0.0001) >> csi_begin;
	cmdl({"-e", "--end"}, 5) >> csi_end;
	cmdl({"-c", "--cut"}, 4) >> csi_cut;

	if(csi_begin<=0.0){
		cout << "The input value of csi_begin=" << csi_begin << 
			" must be >=0="<< endl;
		return 1;
	}else if (csi_begin > csi_end){
		cout << "The input value of csi_begin=" << csi_begin << 
			" must be < than csi_end="<< csi_end << endl;
		return 1;
	}else if (csi_cut > csi_end){
		cout << "The input value of csi_cut=" << csi_cut << 
			" must be <= than csi_end="<< csi_end << endl;
		return 1;
	}else if(csi_cut < csi_begin){
		cout << "The input value of csi_cut=" << csi_cut << 
			" must be >= than csi_begin="<< csi_begin << endl;
		return 1;
	}else if(h > 0.3*(csi_end-csi_begin)){
		cout << "The input value of the step=" << h << 
			" must be <= than 0.3*(csi_end-csi_begin)="<< 
			0.3*(csi_end-csi_begin) << endl;
		return 1;
	}

	RungeKutta myRK;
	BonnorEbert* BE = new BonnorEbert();
	int nstep = int(csi_end/h + 0.5);
	VettoreLineare x(2);
	x.setComponent(0, 0.);
	x.setComponent(1, 0.);
	ofstream uscita_RK;
	uscita_RK.open("Bonnor-Ebert_RK.dat");

	double csi = csi_begin;
	for(int i=0; i<nstep; i++){
		uscita_RK << i << "\t "  << csi << "\t " << x.getComponent(0) << endl;
		x = myRK.Passo(BE, x, h, csi);
		csi += h;
	}

	uscita_RK.close();
	uscita_RK.clear();
	return 0;
}

