#pragma once
#include "Polynom.h"
#include<string>
class TextPolynom :	public Polynom
{
private:
	string text_poly;
public:
	TextPolynom();
	TextPolynom(unsigned int deg);
	TextPolynom(unsigned int deg, int coef[]);
	TextPolynom(TextPolynom& A);
	TextPolynom(Polynom&A);
	~TextPolynom();
	void show();
	void operator=(const TextPolynom& A);
	void operator=(const Polynom& A);
	friend TextPolynom operator+(TextPolynom A, TextPolynom B);
	friend TextPolynom operator-(TextPolynom A, TextPolynom B);
	friend TextPolynom operator*(TextPolynom A, TextPolynom B);
};

