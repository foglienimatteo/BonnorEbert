#include "FunzioneVettoriale.hpp"


BonnorEbert:: BonnorEbert(){}
BonnorEbert:: ~BonnorEbert(){}

VettoreLineare BonnorEbert::Eval(VettoreLineare& y, double csi){
	VettoreLineare f(y.getDimension());
	f.setComponent(0, y.getComponent(1));
	f.setComponent(1, - pow(2.718281828459, -y.getComponent(0)) - 2 * y.getComponent(1)/csi );
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
