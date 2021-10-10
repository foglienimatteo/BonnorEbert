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

#ifndef Vettore_hpp
#define Vettore_hpp

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class Vettore{
public:
	Vettore(unsigned int );
	Vettore(const Vettore& );
	Vettore();
	
	~Vettore();
	
	void setComponent(unsigned int , double );
	
	double getComponent(unsigned int ) const;
	unsigned int getDimension() const;
	
	virtual void Print() const;
	
	Vettore& operator = (const Vettore& );
	
protected:
	unsigned int m_N;
	double* m_v;
};

void scambiaByReference(double &, double &);

#endif /* Vettore_hpp */
