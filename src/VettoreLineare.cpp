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

VettoreLineare:: VettoreLineare(unsigned int N): Vettore(N){}

VettoreLineare:: VettoreLineare(): Vettore(){}

VettoreLineare::~VettoreLineare(){}

double VettoreLineare::CosTheta(VettoreLineare& v){
	if(m_N != v.getDimension()){
		cerr << "Non consentito ottenere CosTheta: i VettoriLineari hanno dim diverse. " << endl;
		cerr << "m_N = " << m_N << ";  v.getDimension() = " << v.getDimension() << endl;
		return 0;
	}
	
	double costheta = 0.;
	for(unsigned int i=0; i<m_N; i++)
		costheta += m_v[i] * v.getComponent(i);
	
	if(costheta == 0.)
		return 0.;
	
	double m1 = Modulo();
	double m2 = v.Modulo();
	costheta /= (m1*m2);
	
	return costheta;
}

double VettoreLineare::Modulo(){
	double modulo = 0.;
	for(unsigned int i=0; i<m_N; i++)
		modulo += pow (m_v[i], 2.);
	
	modulo = sqrt(modulo);
	return modulo;
}

void VettoreLineare::Print() const{
	cout << "Vettore Lineare V = (" << m_v[0];
	for(unsigned int i=1; i<m_N; i++)
		cout << ", " << m_v[i];
	cout << ") " << endl;
}

VettoreLineare VettoreLineare:: operator + (const VettoreLineare& v){
	if(m_N != v.getDimension()){
		cerr << "Non consentita la somma vettoriale: i VettoriLineari hanno dim diverse. " << endl;
		cerr << "m_N = " << m_N << ";  v.getDimension() = " << v.getDimension() << endl;
		return 0;
	}
	
	VettoreLineare* Z = new VettoreLineare(m_N);
	for(unsigned int i=0; i<m_N; i++){
		Z->setComponent(i, m_v[i] + v.getComponent(i));
	}
	
	return *Z;
}

double VettoreLineare:: operator * (const VettoreLineare& v){
	
	if(m_N != v.getDimension()){
		cerr << "Non consentito il prodotto scalare: i VettoriLineari hanno dim diverse. " << endl;
		cerr << "m_N = " << m_N << ";  v.getDimension() = " << v.getDimension() << endl;
		return 0;
	}
	
	double sum = 0.;
	for(unsigned int i=0; i<m_N; i++)
		sum += m_v[i] * v.getComponent(i);
	
	return sum;
}

VettoreLineare VettoreLineare:: operator * (const double x){
	VettoreLineare* Z = new VettoreLineare(m_N);
	
	for(unsigned int i=0; i<m_N; i++)
		Z->setComponent(i,m_v[i] * x);
	
	return *Z;
}

VettoreLineare VettoreLineare::operator = (const VettoreLineare& v){
	m_N = v.getDimension();
	m_v = new double [m_N];
	
	for(unsigned int i=0; i<m_N; i++)
		m_v[i] = v.getComponent(i);
	
	return *this;
}
