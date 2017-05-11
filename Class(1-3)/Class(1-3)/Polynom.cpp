#include"Polynom.h"

Polynom::Polynom() :degree(0)
{
	coefficient = new int[1];
	coefficient[0] = 1;
}

Polynom::Polynom(unsigned int exp) :degree(exp)
{
	coefficient = new int[exp+1];
	for (int i = 0; i < exp; i++)
	{
		coefficient[i] = 0;
	}
	coefficient[exp] = 1;
}

Polynom::Polynom(unsigned int exp,int coef[]) :degree(exp)
{
	coefficient = new int[exp + 1];
	for (int i = 0; i <= exp; i++)
	{
		coefficient[i] = coef[i];
	}
}

//конструктор копирования
Polynom::Polynom( const Polynom &p) 
{
	degree = p.degree;
	coefficient = new int[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coefficient[i] = p.coefficient[i];
	}
}


Polynom::~Polynom()
{
	delete[] coefficient;
}

void Polynom::show() const
{
	bool k=false;
	for (int i = 0; i <= Polynom::degree; i++)
	{
		if (this->coefficient[i] == 0) continue;
		if (this->coefficient[i] > 0)
			cout << (k ? "+" : "");
		if (this->coefficient[i] != 1 && this->coefficient[i] != -1 || i == 0)
			cout << this->coefficient[i];
		if (this->coefficient[i] != 1 && this->coefficient[i] != -1 && i != 0)
			cout << "*";
		if (this->coefficient[i] == -1)
			cout << "-";
		k=true;
		if (i > 0)
		{
			if (i == 1) cout << "x";
			else cout << "x^" << i;
		}
	}
	cout << endl;
	
}

void Polynom::correctCoefficient(unsigned int deg, int coef)
{
	if (deg > degree&&coef != 0)
	{

		int*coeff = new int[deg + 1];
		for (int i = 0; i <= degree; i++)
		{
			coeff[i] = coefficient[i];
		}
		for (int i = degree + 1; i < deg; i++)
		{
			coeff[i] = 0;
		}
		coeff[deg] = coef;
		degree = deg;
		delete coefficient;
		coefficient = coeff;
	}
	else if (degree == deg && coef == 0)
	{
		degree -= 1;
		for (int i = degree; i>=0 && coefficient[i]==0; i--)
		{
			degree -= 1;
		}
	}
	else if (degree > deg) coefficient[deg] = coef;
}

Polynom Polynom::sum(const Polynom& A)
{
	unsigned int min = (A.degree < degree) ? A.degree : degree;
	bool k = (min == A.degree);
	unsigned int max = A.degree + degree-min;
	int*tmpCoef = new int[max + 1];
	for (int i = 0; i <= min; i++)
	{
		tmpCoef[i] = A.coefficient[i] + coefficient[i];
	}
	for (int i = min + 1; i <= max ; i++)
	{
		tmpCoef[i] = k ? coefficient[i] : A.coefficient[i];
	}
	Polynom tmp(max, tmpCoef) ;
	return tmp;
}


Polynom Polynom::unsum(const Polynom& A)
{
	unsigned int min = (A.degree < degree) ? A.degree : degree;
	unsigned int max = A.degree + degree - min;
	int*tmpCoef = new int[max+1];
	for (int i = 0; i <= min; i++)
		tmpCoef[i] = coefficient[i] - A.coefficient[i];
	for (int i = min + 1; i <= max; i++)
		tmpCoef[i] = -A.coefficient[i];
	Polynom tmp(max, tmpCoef);
	return tmp;
}


Polynom Polynom::product(const Polynom& B)
{
	unsigned int degTemp = B.degree + degree;
	int*tmpCoef = new int[degTemp+1];
	for (int i = 0; i <= degTemp; i++)
		tmpCoef[i] = 0;
	for (int i = 0; i <= degree; i++)
		for (int j = 0; j <= B.degree; j++)
			tmpCoef[i+j] += coefficient[i]* coefficient[i];
	Polynom tmp (degTemp, tmpCoef);
	return tmp;
}

double Polynom::value(double x)
{
	double result=0;
	for (int i = 0; i <= degree; i++)
	{
		result += coefficient[i] * pow(x, i);
	}
	return result;
}

int Polynom::getDeg() const
{
	return degree;
}

int Polynom::getCoef(unsigned int n) const
{
	if (n <= degree) return coefficient[n];
}

