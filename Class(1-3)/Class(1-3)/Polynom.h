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
	Polynom sum(const Polynom& A);
	Polynom unsum(const Polynom& A);
	Polynom product(const Polynom& A);
	double value(double x);
	int getDeg() const;
	int getCoef(unsigned int n) const;

	friend Polynom operator+(Polynom A, Polynom B);
	friend Polynom operator-(Polynom A, Polynom B);
	friend Polynom operator*(Polynom A, Polynom B);
	friend ostream& operator<<(ostream& os, const Polynom &A);
	friend istream& operator>>(istream& is, Polynom &A);
	double operator()(double x);
	void operator=(const Polynom& A);
	bool operator>=(const Polynom& A);
	bool operator<=(const Polynom& A);
	bool operator>(const Polynom& A);
	bool operator<(const Polynom& A);
	bool operator==(const Polynom& A);
	bool operator!=(const Polynom& A);
	Polynom& operator++();
	Polynom operator++(int);
	Polynom& operator--();
	Polynom operator--(int);


private:

	unsigned int degree;
	int *coefficient;
};

