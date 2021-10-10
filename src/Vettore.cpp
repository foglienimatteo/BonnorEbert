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






