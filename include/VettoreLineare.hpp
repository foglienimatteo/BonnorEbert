#ifndef VettoreLineare_hpp
#define VettoreLineare_hpp

#include "Vettore.hpp"
#include <cmath>

class VettoreLineare:public Vettore{
public:
	VettoreLineare(unsigned int );
	VettoreLineare();
	
	~VettoreLineare();
	
	double CosTheta(VettoreLineare& );
	double Modulo();
	void Print() const;
	
	VettoreLineare operator + (const VettoreLineare& );
	double operator * (const VettoreLineare& );
	VettoreLineare operator * (const double );
	VettoreLineare operator = (const VettoreLineare& );
};

#endif /* VettoreLineare_hpp */
