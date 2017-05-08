#pragma once


#include <iostream>

using namespace std;


class Polynom
{
public:
	Polynom();
	Polynom(unsigned int deg);
	Polynom(unsigned int deg, double coef[]);
	Polynom(const Polynom &p);
	~Polynom();
	void show() const;
	void correctCoefficient(unsigned int deg,double coef);
	int getDeg() const;
	double *getCoef() const;
	Polynom sum(const Polynom& A);
	Polynom unsum(const Polynom& A);
	Polynom product(const Polynom& A);

private:

	unsigned int degree;
	double *coefficient;

};

