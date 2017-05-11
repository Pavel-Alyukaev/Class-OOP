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
	Polynom CC = A + B;
	cout << "'+'= ";
	CC.show();
	Polynom D = A.unsum(B);
	cout << "Unsum ";
	D.show();
	Polynom DD = A - B;
	cout << "'-'= ";
	DD.show();
	Polynom E = A.product(B);
	cout << "Product ";
	E.show();
	Polynom EE = A * B;
	cout << "'*'= ";
	EE.show();
	cout << "A=";
	A.show();
	cout << "B=";
	B.show();
	cout << "B=" << B << endl;
	cout << "B(1)=";
	cout << B.value(1) << endl;
	cout << "(1)=";
	cout << B(1) << endl;
	Polynom QQ;
	//QQ.correctCoefficient(7, 1);
	cin >> QQ;
	cout << "QQ=" << QQ << endl;
	QQ.~Polynom();
	
	system("pause");

}


int* randCoef(int n)
{
	int* b = new int[n+1];
	for (int i = 0; i < n+1; i++)
	{
		b[i] = rand() % 21-10;
	}
	return b;
}