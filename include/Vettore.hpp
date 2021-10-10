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
