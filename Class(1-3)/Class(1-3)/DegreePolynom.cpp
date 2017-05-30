#include "DegreePolynom.h"



DegreePolynom::DegreePolynom()
{
	Polynom A;
	*this = A;
	degreeCoef = new int[degree + 1];
	int k = 0;
	for (int i = 0; i <= degree; i++)
	{
		degreeCoef[i] = 0;
		if (coefficient[i] != 0)
			degreeCoef[k++] = i;
	}

}

DegreePolynom::DegreePolynom(unsigned int deg)
{
	Polynom A(deg);
	*this = A;
	degreeCoef = new int[degree + 1];
	int k = 0;
	for (int i = 0; i <= degree; i++)
	{
		degreeCoef[i] = 0;
		if (coefficient[i] != 0)
			degreeCoef[k++] = i;
	}
}

DegreePolynom::DegreePolynom(unsigned int deg, int coef[])
{
	Polynom A(deg, coef);
	*this = A;
	degreeCoef = new int[degree + 1];
	int k = 0;
	for (int i = 0; i <= degree; i++)
	{
		degreeCoef[i] = 0;
		if (coefficient[i] != 0)
			degreeCoef[k++] = i;
	}
}

DegreePolynom::DegreePolynom(DegreePolynom& A)
{
	degree = A.degree;
	coefficient= new int[degree + 1];
	degreeCoef = new int[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coefficient[i] = A.coefficient[i];
		degreeCoef[i] = A.degreeCoef[i];
	}
}

DegreePolynom::DegreePolynom(Polynom&A)
{
	degree = A.getDeg();
	coefficient = new int[degree + 1];
	degreeCoef = new int[degree + 1];
	int k = 0;
	for (int i = 0; i <= degree; i++)
	{
		coefficient[i] = A.getCoef(i);
		degreeCoef[i] = 0;
		if (coefficient[i] != 0)
			degreeCoef[k++] = i;
	}
}


DegreePolynom::~DegreePolynom()
{
	delete[] degreeCoef;
}

int DegreePolynom::getDegreeCoef(int i)
{
	return degreeCoef[i];
}


void DegreePolynom::operator=(const DegreePolynom& A)
{
	{
		degree = A.degree;
		delete[] coefficient;
		delete[] degreeCoef;
		coefficient = new int[degree + 1];
		degreeCoef = new int[degree + 1];
		for (int i = 0; i <= degree; i++)
		{
			coefficient[i] = A.coefficient[i];
			degreeCoef[i] = A.degreeCoef[i];
		}
	}
}

void DegreePolynom::operator=(const Polynom& A)
{
	int k = 0;
	degree = A.getDeg();
	delete[] coefficient;
	delete[] degreeCoef;
	coefficient = new int[degree + 1];
	degreeCoef = new int[degree + 1];
	for (int i = 0; i < degree + 1; i++)
	{
		coefficient[i] = A.getCoef(i);
		degreeCoef[i] = 0;
		if (coefficient[i] != 0)
			degreeCoef[k++] = i;
		cerr <<" k= "<< k << " ";
	}
}

int DegreePolynom::maxDegCoef()
{
	int max;
	int i = 0;
	while (degreeCoef[i]!=0)
	{
		max = degreeCoef[i++];
	}
	return max;
}

int DegreePolynom::minDegCoef()
{
	return degreeCoef[0];
}

