#include"Polynom.h"
#include"TextPolynom.h"
#include"DegreePolynom.h"
#include<Windows.h>
#include<locale.h>
#include<ctime>
#include<fstream>

int* randCoef(int n);
void showIncrement(Polynom P[]);
void showBool(Polynom P[]);
void showOperator(Polynom P[]);
void showMathMetods(Polynom P[]);
void outputF(Polynom P[], int n);
void inputF(Polynom P[], int n);
void input(Polynom P[], int n);
void correct(Polynom &P, int n, int NewCoef);
void firstDate(Polynom P[]);
void WorkingWithTextPolynom();//********
void WorkingWithDegreePolynom();//**********

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	Polynom *P = new Polynom[9];
	Polynom A(3,randCoef(3));
	Polynom B(4, randCoef(4));
	P[0] = A;
	P[1] = B;
	firstDate(P);
	correct(P[1], 7, 1);
	showMathMetods(P);
	showOperator(P);
	showIncrement(P);
	showBool(P);
	input(P,8);
	outputF(P,9);
	delete[] P;
	Polynom *P_read = new Polynom[9];
	inputF(P_read, 9);
	WorkingWithTextPolynom();
	WorkingWithDegreePolynom();
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

void showIncrement(Polynom P[])
{
	cout << "******инкрименты*****" << endl;
	cout << "P[0]++ = " << P[0]++ << endl;
	cout << "P[0] = " << P[0] << endl;
	cout << "++P[0] = " << ++P[0] << endl;
	cout << "--P[0] = " << --P[0] << endl;
	cout << "P[0]-- = " << P[0]-- << endl;
	cout << "P[0] = " << P[0] << endl;
}

void showBool(Polynom P[])
{
	cout << "******Булевы операции*****" << endl;
	cout << "P[0] > P[1] = " << (P[0] > P[1]) << endl;
	cout << "P[0] < P[1] = " << (P[0] < P[1]) << endl;
	cout << "P[1] < P[1] = " << (P[1] < P[1]) << endl;
	cout << "P[1] <= P[1] = " << (P[1] <= P[1]) << endl;
	cout << "P[0] == P[1] = " << (P[0] == P[1]) << endl;
	cout << "P[1] == P[1] = " << (P[1] == P[1]) << endl;
	cout << "P[0] != P[1] = " << (P[0] != P[1]) << endl;
	cout << "P[0] != P[0] = " << (P[0] != P[0]) << endl;
}

void showOperator(Polynom P[])
{
	cout << "******перегрузка операторов*****" << endl;
	P[5] = P[0] + P[1];
	cout << "'+'= " << P[5] << endl;
	P[6] = P[0] - P[1];
	cout << "'-'= " << P[6] << endl;
	P[7] = P[0] * P[1];
	cout << "'*'= " << P[7] << endl;
	cout << "(1)=" << P[1](1) << endl;


}

void showMathMetods(Polynom P[])
{
	cout << "******матиматические методы*****" << endl;
	cout << "Sum ";
	P[2] = P[0].sum(P[1]);
	P[2].show();
	P[3] = P[0].unsum(P[1]);
	cout << "Unsum ";
	P[3].show();
	P[4] = P[0].product(P[1]);
	cout << "Product ";
	P[4].show();
	cout << "P[0]=";
	P[0].show();
	cout << "P[1]=";
	P[1].show();
	cout << "P[1](1)=" << P[1].value(1) << endl;

}

void outputF(Polynom P[],int n)
{
	ofstream fout("cppstudio.txt");
	for (int i = 0; i < n; i++)
	{
		fout << P[i];
	}
	fout.close();

	cout << "******вывод из файла*****" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "P_read[" << i << "]=" << P[i] << endl;
	}
}

void inputF(Polynom P[], int n)
{
	ifstream fin("cppstudio.txt");
	for (int i = 0; i < n; i++)
	{
		fin >> P[i];
	}
	fin.close();

}

void input(Polynom P[], int n)
{
	cout << "******ввод с клавиатуры*****" << endl;
	cin >> P[n];
	//cout << " P[" << n << "]=" << P[n] << endl;

}

void correct(Polynom &P,int n, int NewCoef)
{
	cout << "******корректировка коэффициентов*****" << endl;
	cout << "Correct P=";
	P.correctCoefficient(n, NewCoef);
	P.show();
	cout << "P degree = " << P.getDeg() << endl;
	cout << "P coefficient = ";
	for (int i = 0; i <= P.getDeg(); i++)
	{
		cout << P.getCoef(i) << " ";
	}
	cout << endl;
	cout << "Correct P[1]=";
	P.correctCoefficient(7, 0);
	P.show();
	cout << "P degree = " << P.getDeg() << endl;

}

void firstDate(Polynom P[])
{
	cout << "******исходные полиномы*****" << endl;
	cout << "P[0]=";
	P[0].show();
	cout << "P[1]=";
	P[1].show();

}

void WorkingWithTextPolynom()
{
	cout << "*********TextPolynom***********" << endl;
	TextPolynom Q(2, randCoef(2));
	cout << Q << endl;
	Q.show();
	Q.correctCoefficient(5, 2);
	cout << Q << endl;
	TextPolynom QQ;
	QQ = Q + Q;
	cout << QQ << endl;

}

void WorkingWithDegreePolynom()
{
	cout << "*********DegreePolynom***********" << endl;
	
	Polynom A;
	input(&A, 0);
	DegreePolynom Q = A;
	cout << Q << endl;
	int i = 0;
	while (Q.getDegreeCoef(i) != 0 && i < Q.getDeg())
	{
		cout << Q.getDegreeCoef(i++)<<" ";
	}
	cout << endl;
	cout << "max degree = "<<Q.maxDegCoef() << endl;
	cout << "min degree = "<<Q.minDegCoef() << endl;

}