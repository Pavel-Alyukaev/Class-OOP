#include"Polynom.h"
#include<Windows.h>
#include<locale.h>

#include<ctime>

int* randCoef(int n);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	Polynom A(2, randCoef(3));
	Polynom B(4, randCoef(4));
	cout << "*************Исходные полиномы ***************" << endl;
	cout << "A=";
	A.show();
	cout << "B=";
	B.show();
	cout << "*******корректирование коэффициентов *********" << endl;
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
	cout << "B degree = " <<B.getDeg() << endl;
	cout << "**********математические операции ************" << endl;
	cout << "Sum ";
	Polynom C = A.sum(B);
	C.show();
	Polynom D = A.unsum(B);;
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

	cout << "**********Перегрузка операторов ************" << endl;
	cout << "A=" << A << endl;
	cout << "B=" << B << endl;
	cout << "B(1)="<< B(1) << endl;
	Polynom CC = A + B;
	cout << "'+'= "<<CC<<endl;
	Polynom DD = A - B;
	cout << "'-'= "<<DD<<endl;
	Polynom EE = A * B;
	cout << "'*'= "<<EE<<endl;


	cout << "**********ввод с клавиатуры************" << endl;
	Polynom QQ;
	cin >> QQ;
	cout << "QQ=" << QQ << endl;

	ofstream fout("open.txt");
	ofstream("open.txt", ios::app); 
	fout << A << B;
	fout.close();
	Polynom *FC=new Polynom[2];

	cout << "**********ввод из файла************" << endl;
	ifstream fin("open.txt");
	fin >> FC[0]>>FC[1];
	fin.close();
	cout << "**********инкрименты************" << endl;
	cout << "FC[0]=" << FC[0] << endl;
	cout << "FC[1]=" << FC[1] << endl;
	cout << "FC[0]++=" << FC[0]++ << endl;
	cout << "++FC[0]=" << ++FC[0] << endl;
	cout << "--FC[0]=" << --FC[0] << endl;
	cout << "FC[0]--=" << FC[0]-- << endl;
	cout << "FC[0]=" << FC[0] << endl;
	cout << "--(--(--FC[0]))=" << --(--(--FC[0])) << endl;
	Polynom qqq = FC[1].sum(FC[1]);
	cout << qqq << endl;




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