#pragma once
#include "Polynom.h"
class DegreePolynom : public Polynom
{
protected:
	int* degreeCoef;
public:
	DegreePolynom();
	DegreePolynom(unsigned int deg);
	DegreePolynom(unsigned int deg, int coef[]);
	DegreePolynom(DegreePolynom& A);
	DegreePolynom(Polynom&A);
	~DegreePolynom();
	int getDegreeCoef(int i);
	void operator=(const DegreePolynom& A);
	void operator=(const Polynom& A);
	int maxDegCoef();
	int minDegCoef();
	
};

