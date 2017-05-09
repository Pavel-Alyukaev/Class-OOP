#pragma once


#include <iostream>
#include<math.h>

using namespace std;


class Polynom
{
public:
	Polynom();
	Polynom(unsigned int deg);
	Polynom(unsigned int deg, int coef[]);
	Polynom(const Polynom &p);
	~Polynom();
	void show() const;
	void correctCoefficient(unsigned int deg,int coef);
	int getDeg() const;
	int *getCoef() const;
	Polynom sum(const Polynom& A);
	Polynom unsum(const Polynom& A);
	Polynom product(const Polynom& A);
	double value(double x);

private:

	unsigned int degree;
	int *coefficient;

};

