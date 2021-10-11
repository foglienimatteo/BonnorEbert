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

#include "FunzioneVettoriale.hpp"


BonnorEbert:: BonnorEbert(){}
BonnorEbert:: ~BonnorEbert(){}

VettoreLineare BonnorEbert::Eval(VettoreLineare& y, double csi){
	VettoreLineare f(y.getDimension());
	f.setComponent(0, y.getComponent(1));
	f.setComponent(1, pow(2.718281828459, -y.getComponent(0)) - 2 * y.getComponent(1)/csi );
	return f;
}


Eulero::Eulero(){}
Eulero::~Eulero(){}

VettoreLineare Eulero::Passo(FunzioneVettorialeBase* f, VettoreLineare& y0, double h, double t)const{
	VettoreLineare y = y0 + (f->Eval(y0,t))*h;
	return y;
}

VettoreLineare RungeKutta::Passo(FunzioneVettorialeBase* f, VettoreLineare& y0, double h, double t) const {
	int dim = y0.getDimension();
	VettoreLineare k1(dim), k2(dim), k3(dim), k4(dim);

	k1 = f->Eval(y0, t);
	VettoreLineare p = y0 + k1*(h/2.);
	k2 = f->Eval(p, t+h/2.);
	p = y0 + k2*(h/2.);
	k3 = f->Eval (p, t+h/2.);
	p = y0 + k3*h;
	k4 = f->Eval (p, t+h);

	VettoreLineare y = y0 + (k1 + k2*2.+ k3*2. + k4)*(h/6.);
	return y;
}

RungeKutta::RungeKutta(){}
RungeKutta::~RungeKutta(){}
