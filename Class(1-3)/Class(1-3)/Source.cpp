#include"Polynom.h"
#include<Windows.h>
#include<locale.h>
#include<ctime>

int* randCoef(int n);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	Polynom A(3, randCoef(3));
	Polynom B(4, randCoef(4));
	
	cout << "A=";
	A.show();
	cout << "B=";
	B.show();
	cout << "Sum ";
	Polynom C=A.sum(B); 
	C.show();
	Polynom D = A.unsum(B);
	cout << "Unsum ";
	D.show();
	Polynom E = A.product(B);
	cout << "Product ";
	E.show();
	cout << "A=";
	A.show();
	cout << "B=";
	B.show();
	 
	system("pause");

}


int* randCoef(int n)
{
	int* b = new int[n+1];
	for (int i = 0; i < n+1; i++)
	{
		b[i] = rand() % 10;
	}
	return b;
}