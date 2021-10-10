#include "VettoreLineare.hpp"
#include "Vettore.hpp"
#include "FunzioneVettoriale.hpp"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

//#include "argh.h"

#define pi 3.141592653589

using namespace std;

//void assert_close(double ,double );
//void test_program(VettoreLineare , Eulero , OscillatoreArmonico* );

int main(int argc, char ** argv){
	if(argc!=4){
		cerr << "Tipo di input: " << argv[0] << " <passo_di_integrazione> <csi_in> <csi_massimo>" << endl;
		return -1;
	}

	double h = atof(argv[1]);
	double csi = atof(argv[2]);
	double csi_max = atof(argv[3]);

	Eulero myEuler;
	//RungeKutta myRK;

	BonnorEbert* BE = new BonnorEbert();

	int nstep = int(csi_max/h + 0.5);

	VettoreLineare x(2);
	x.setComponent(0, 0.);
	x.setComponent(1, 0.);

	//test_program(x,myEuler,LE);

	ofstream uscita_Eulero;
	uscita_Eulero.open("Bonnor-Ebert_Eulero.dat");
	//ofstream uscita_RK;
	//uscita_RK.open("LE_RK.dat");

	for(int i=0; i<nstep; i++){
		uscita_Eulero << i << "\t "  << csi << "\t " << x.getComponent(0) << endl;
		//uscita_RK << i << "\t "  << csi << "\t " << x.getComponent(0) << endl;
		x = myEuler.Passo(BE, x, h, csi);
		csi += h;
	}

	uscita_Eulero.close();
	uscita_Eulero.clear();
	//uscita_RK.close();
	//uscita_RK.clear();

	return 0;
}
