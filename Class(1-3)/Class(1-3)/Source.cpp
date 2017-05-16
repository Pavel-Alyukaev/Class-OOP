#include"Polynom.h"
#include<Windows.h>
#include<locale.h>
#include<ctime>

int* randCoef(int n);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	Polynom *P = new Polynom[9];
	Polynom A(3, randCoef(3));
	Polynom B(4, randCoef(4));
	cout << "******исходные полиномы*****" << endl;
	P[0] = A;
	P[1] = B;
	cout << "P[0]=";
	P[0].show();
	cout << "P[1]=";
	P[1].show();
	cout << "******корректировка коэффициентов*****" << endl;
	cout << "Correct P[1]=";
	P[1].correctCoefficient(7, 1);
	P[1].show();
	cout << "P[1] degree = " << P[1].getDeg() << endl;
	cout << "P[1] coefficient = ";
	for (int i = 0; i <= P[1].getDeg(); i++)
	{
		cout << P[1].getCoef(i)<<" ";
	}
	cout << endl;
	cout << "Correct P[1]=";
	P[1].correctCoefficient(7, 0);
	P[1].show();
	cout << "P[1] degree = " << P[1].getDeg() << endl;
	cout << "******матиматические методы*****" << endl;
	cout << "Sum ";
	P[2]= P[0].sum(P[1]);
	P[2].show();
	P[3] = P[0].unsum(P[1]);
	cout << "Unsum ";
	P[3].show();
	P[4] = P[0].product(P[1]);
	cout << "Product ";
	P[4].show();
	P[0].show();
	cout << "P[1]=";
	P[1].show();
	cout << "P[1]=" << B << endl;
	cout << "P[1](1)=" << P[1].value(1) << endl;
	cout << "******перегрузка операторов*****" << endl;
	P[5] = P[0] + P[1];
	cout << "'+'= " << P[5] << endl;
	P[6] = P[0] - P[1];
	cout << "'-'= " << P[6] << endl;
	P[7] = P[0] * P[1];
	cout << "'*'= " << P[7] << endl;
	cout << "(1)=" << P[1](1) << endl;
	cout << "******Булевы операции*****" << endl;
	
	cout << "P[0] > P[1] = " << (P[0] > P[1]) << endl;
	cout << "P[0] < P[1] = " << (P[0] < P[1]) << endl;
	cout << "P[1] < P[1] = " << (P[1] < P[1]) << endl;
	cout << "P[1] <= P[1] = " << (P[1] <= P[1]) << endl;
	cout << "P[0] == P[1] = " << (P[0] == P[1]) << endl;
	cout << "P[1] == P[1] = " << (P[1] == P[1]) << endl;
	cout << "P[0] != P[1] = " << (P[0] != P[1]) << endl;
	cout << "P[0] != P[0] = " << (P[0] != P[0]) << endl;


	cout << "******ввод с клавиатуры*****" << endl;
	cin >> P[8];
	cout << "QQ=" << P[8] << endl;

	






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