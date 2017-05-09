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
	if (this->degree >= deg) this->coefficient[deg] = coef;
}

int Polynom::getDeg() const
{
	return this->degree;
}

int* Polynom::getCoef() const
{
	return this->coefficient;
}

Polynom Polynom::sum(const Polynom& A)
{
	unsigned int degA = A.getDeg();
	unsigned int degB = this->getDeg();
	unsigned int min = (degA < degB) ? degA : degB;
	bool k = (min == degA);
	unsigned int max = k ? degB : degA;
	int*tmpCoef = new int[max + 1];
	int* tmpA = A.getCoef();
	int* tmpB = this->getCoef();
	for (int i = 0; i <= min; i++)
	{
		tmpCoef[i] = tmpA[i] + tmpB[i];
	}
	for (int i = min + 1; i <= max ; i++)
	{
		tmpCoef[i] = k ? tmpB[i] : tmpA[i];
	}
	Polynom tmp(max, tmpCoef) ;
	return tmp;

}


Polynom Polynom::unsum(const Polynom& A)
{
	unsigned int degA = A.getDeg();
	unsigned int degB = this->getDeg();
	unsigned int min = (degA < degB) ? degA : degB;
	bool k = (min == degA);
	unsigned int max = k ? degB : degA;
	int*tmpCoef = new int[max+1];
	int* tmpA = A.getCoef();
	int* tmpB = this->getCoef();
	for (int i = 0; i <= min; i++)
		tmpCoef[i] = tmpB[i] - tmpA[i];
	for (int i = min + 1; i <= max; i++)
		tmpCoef[i] = -tmpA[i];
	Polynom tmp(max, tmpCoef);
	return tmp;
}


Polynom Polynom::product(const Polynom& B)
{
	unsigned int degA = this->getDeg();
	unsigned int degB = B.getDeg();
	unsigned int degTemp = degA + degB;

	int*tmpCoef = new int[degTemp+1];
	int* tmpA = this->getCoef();
	int* tmpB = B.getCoef();

	for (int i = 0; i <= degTemp; i++)
		tmpCoef[i] = 0;
	for (int i = 0; i <= degA; i++)
		for (int j = 0; j <= degB; j++)
			tmpCoef[i+j] += tmpA[i]*tmpB[j];
	
	Polynom tmp (degTemp, tmpCoef);
	return tmp;
}

double Polynom::value(double x)
{
	double result=0;
	for (int i = 0; i <= this->degree; i++)
	{
		result += this->coefficient[i] * pow(x, i);
	}
	return result;
}