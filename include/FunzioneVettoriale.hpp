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

#ifndef FunzioneVettoriale_hpp
#define FunzioneVettoriale_hpp

#include "VettoreLineare.hpp"

class FunzioneVettorialeBase{
public:
	virtual VettoreLineare Eval(VettoreLineare& y, double t) = 0;
};



class EquazioneDifferenzialeBase{
public:
	virtual VettoreLineare Passo(FunzioneVettorialeBase* f, VettoreLineare& y0, double h, double t)const = 0;
};



class BonnorEbert: public FunzioneVettorialeBase{
public:
	BonnorEbert();

	~BonnorEbert();

	virtual VettoreLineare Eval(VettoreLineare& y, double csi);
};



class Eulero: public EquazioneDifferenzialeBase{
public:
	Eulero();

	~Eulero();

	virtual VettoreLineare Passo(FunzioneVettorialeBase* f, VettoreLineare& y0, double h, double t)const;
};

class RungeKutta: public EquazioneDifferenzialeBase{
public:
	RungeKutta();

	~RungeKutta();

	virtual VettoreLineare Passo(FunzioneVettorialeBase* f, VettoreLineare& y0, double h, double t) const;
};

#endif /* FunzioneVettoriale_hpp */
