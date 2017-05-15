#pragma once

#include <iostream>
#include<math.h>
#include <fstream> 

using namespace std;
class Polynom
{
public:
	Polynom::Polynom();
	Polynom::Polynom(unsigned int deg);
	Polynom::Polynom(unsigned int deg, int coef[]);
	Polynom::Polynom(const Polynom &p);
	Polynom::~Polynom();
	void show() const;
	void correctCoefficient(unsigned int deg,int coef);
	Polynom sum(const Polynom& A);
	Polynom unsum(const Polynom& A);
	Polynom product(const Polynom& A);
	double value(double x);
	int getDeg() const;
	int getCoef(unsigned int n) const;
	Polynom& operator++();
	Polynom operator++(int);
	Polynom& operator--();
	Polynom operator--(int);

	friend Polynom operator+(Polynom A, Polynom B);
	friend Polynom operator-(Polynom A, Polynom B);
	friend Polynom operator*(Polynom A, Polynom B);
	friend ostream& operator<<(ostream& os, const Polynom &A);
	friend istream& operator>>(istream& is, Polynom &A);
	//friend Polynom operator++(Polynom& A);
	double operator()(double x);
	

private:

	unsigned int degree;
	int *coefficient;
};

