#include"Polynom.h"

Polynom::Polynom() :degree(0)
{
	coefficient = new double[1];
	coefficient[0] = 1;
	//cerr << "constr" << endl;
}

Polynom::Polynom(unsigned int exp) :degree(exp)
{
	coefficient = new double[exp+1];
	for (int i = 0; i < exp; i++)
	{
		coefficient[i] = 0;
	}
	coefficient[exp] = 1;
	//cerr << "constr" << endl;
}

Polynom::Polynom(unsigned int exp,double coef[]) :degree(exp)
{
	coefficient = new double[exp + 1];
	for (int i = 0; i <= exp; i++)
	{
		coefficient[i] = coef[i];
	}
	//cerr << "constr" << endl;
}

//конструктор копирования
Polynom::Polynom( const Polynom &p) 
{
	degree = p.degree;
	coefficient = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coefficient[i] = p.coefficient[i];
	}
	//cerr << "constr" << endl;
}


Polynom::~Polynom()
{
	delete[] coefficient;
	//cerr << "destr" << endl;
}

void Polynom::show() const
{
	bool k=false;
	for (int i = 0; i <= Polynom::degree; i++)
	{
		if (Polynom::coefficient[i] == 0) continue;
		if (Polynom::coefficient[i] > 0)
			cout << (k ? "+" : "");
		if (Polynom::coefficient[i] != 1 && Polynom::coefficient[i] != -1 || i == 0)
			cout << Polynom::coefficient[i];
		if (Polynom::coefficient[i] != 1 && Polynom::coefficient[i] != -1 && i != 0)
			cout << "*";
		if (Polynom::coefficient[i] == -1)
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

void Polynom::correctCoefficient(unsigned int deg, double coef)
{
	if (Polynom::degree >= deg) Polynom::coefficient[deg] = coef;
}

int Polynom::getDeg() const
{
	return Polynom::degree;
}

double* Polynom::getCoef() const
{
	return Polynom::coefficient;
}

Polynom Polynom::sum(const Polynom& A)
{
	unsigned int degA = A.getDeg();
	unsigned int degB = this->getDeg();
	unsigned int min = (degA < degB) ? degA : degB;
	bool k = (min == degA);
	unsigned int max = k ? degB : degA;
	double*tmpCoef = new double[max + 1];
	double* tmpA = A.getCoef();
	double* tmpB = this->getCoef();
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
	double*tmpCoef = new double[max+1];
	double* tmpA = A.getCoef();
	double* tmpB = this->getCoef();
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

	double*tmpCoef = new double[degTemp+1];
	double* tmpA = this->getCoef();
	double* tmpB = B.getCoef();

	for (int i = 0; i <= degTemp; i++)
		tmpCoef[i] = 0;
	for (int i = 0; i <= degA; i++)
		for (int j = 0; j <= degB; j++)
			tmpCoef[i+j] += tmpA[i]*tmpB[j];
	
	Polynom tmp (degTemp, tmpCoef);
	return tmp;
}