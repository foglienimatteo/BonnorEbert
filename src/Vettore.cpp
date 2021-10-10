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


#include "Vettore.hpp"

Vettore::Vettore(){
	m_N = 0;
	m_v = NULL;
}

Vettore::Vettore(unsigned int N){
	m_N = N;
	m_v = new double [m_N];
}

Vettore::Vettore(const Vettore& V){
	/*
	 m_N = V.m_N;
	 m_v = new double [m_N];
	 for(unsigned int i=0; i<m_N; i++)
	 m_v[i] = V.m_v[i];
	 */
	
	m_N = V.getDimension();
	m_v = new double [m_N];
	for(unsigned int i=0; i<m_N; i++)
		m_v[i] = V.getComponent(i);
}

Vettore::~Vettore(){}


void Vettore::setComponent(unsigned int i, double x){
	if(i<m_N)
		m_v[i] = x;
	else
		cerr << "Componente inesistente." << endl;
}

double Vettore::getComponent(unsigned int i) const{
	if(i<m_N)
		return m_v[i];
	else{
		cerr << "Componente inesistente." << endl;
		return 0;
	}
}

unsigned int Vettore::getDimension() const{
	return m_N;
}

void Vettore::Print() const{
	for(unsigned int i=0; i<m_N; i++)
		cout << setw(3) <<i<<") " << m_v[i] << endl;
}

Vettore& Vettore:: operator = (const Vettore& V){
	/*
	m_N = V.m_N;
	if(m_v)
		delete []m_v;
	m_v = new double [m_N];
	for (unsigned int i=0; i<m_N; i++)
		m_v[i] = V.m_v[i];
	return *this;
	*/
	
	m_N = V.getDimension();
	if(m_v)
		delete []m_v;
	m_v = new double [m_N];
	for (unsigned int i=0; i<m_N; i++)
		m_v[i] = V.getComponent(i);
	return *this;
}


void scambiaByReference(double &a, double &b){
	double c = a;
	a = b;
	b = c;
}






