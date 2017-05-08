#include"Polynom.h"
#include<Windows.h>
#include<locale.h>


void main()
{
	double* b = new double[4];
	for (int i = 0; i < 4; i++)
	{
		b[i] = i;
	}
	Polynom A(3,b);
	Polynom B(4);
	setlocale(LC_ALL, "rus");
	cout << "A=";
	A.show();
	cout << "B=";
	B.show();
	cout << "C=";
	Polynom C=A.sum(B); 
	C.show();
	Polynom D = A.unsum(B);
	cout << "D=";
	D.show();
	Polynom E = A.product(B);
	cout << "E=";
	E.show();
	cout << "A=";
	A.show();
	cout << "B=";
	B.show();
	
	system("pause");

}