
#include "TextPolynom.h"
#include"Pattern.h"
#include<iostream>
#include<string.h>



TextPolynom::TextPolynom()
{
	Polynom A;
	*this = A;
	text_poly = toString(A);
}

TextPolynom::TextPolynom(unsigned int deg)
{
	Polynom A(deg);
	*this = A;
	text_poly = toString(A);
}

TextPolynom::TextPolynom(unsigned int deg, int coef[])
{
	Polynom A(deg,coef);
	*this = A;
	text_poly = toString(A);
}

TextPolynom::TextPolynom(TextPolynom& A)
{
	*this = A;
}

TextPolynom::TextPolynom(Polynom&A)
{
	*this = A;
	text_poly = toString(A);
}


TextPolynom::~TextPolynom()
{
	
}

void TextPolynom::show()
{
	cout << text_poly << endl;
}

void TextPolynom::operator=(const TextPolynom& A)
{
	{
		degree = A.degree;
		delete[] coefficient;
		coefficient = new int[degree + 1];
		for (int i = 0; i <= degree; i++)
		{
			coefficient[i] = A.coefficient[i];
		}
		text_poly = A.text_poly;
	}
}

void TextPolynom::operator=(const Polynom& A)
{
	degree = A.getDeg();
	delete[] coefficient;
	coefficient = new int[degree + 1];
	for (int i = 0; i < degree+1; i++)
	{
		coefficient[i] = A.getCoef(i);
	}
	text_poly = toString(A);

}


TextPolynom operator+(TextPolynom A, TextPolynom B)
{
	Polynom *P = new Polynom[2];
	TextPolynom result;
	P[0] = A;
	P[1] = B;
	result = P[0]+P[1];
	result.text_poly = toString(P);
	return result;
}
TextPolynom operator-(TextPolynom A, TextPolynom B) 
{
	Polynom *P = new Polynom[2];
	TextPolynom result;
	P[0] = A;
	P[1] = B;
	result = P[0] - P[1];
	result.text_poly = toString(P);
	return result;
};
TextPolynom operator*(TextPolynom A, TextPolynom B) 
{
	Polynom *P = new Polynom[2];
	TextPolynom result;
	P[0] = A;
	P[1] = B;
	result = P[0] * P[1];
	result.text_poly = toString(P);
	return result;
};

