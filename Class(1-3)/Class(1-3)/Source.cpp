#include"Polynom.h"
#include<Windows.h>
#include<ctime>

int* randCoef(int n);

void main()
{
	srand(time(0));
	Polynom A(3, randCoef(3));
	Polynom B(4, randCoef(4));
	cout << "A=";
	A.show();
	cout << "B=";
	B.show();
	cout << "Correct B=";
	B.correctCoefficient(7, 1);
	B.show();
	cout << "B degree = " << B.getDeg() << endl;
	cout << "B coefficient = ";
	for (int i = 0; i <= B.getDeg(); i++)
	{
		cout << B.getCoef(i)<<" ";
	}
	cout << endl;
	cout << "Correct B=";
	B.correctCoefficient(7, 0);
	B.show();
	cout << "B degree = " << B.getDeg() << endl;
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
	cout << "B(1)=";
	cout << B.value(1) << endl;
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