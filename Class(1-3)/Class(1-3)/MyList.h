#pragma once
#include <iostream>

template<class T>
struct Node       //Структура являющаяся звеном списка
{
	T x;     //Значение x будет передаваться в список
	Node *Next, *Prev; //Указатели на адреса следующего и предыдущего элементов списка
};

template<class T>
class List
{
	Node<T> *Head, *Tail;
public:
	List();
	~List();
	void ShowLine();
	void ShowCol();
	void Add(T x);
	void Del();
};

template<class T>
List<T>::List() :Head(NULL), Tail(NULL) 
{

}

template<class T>
List<T>::~List()
{
	while (Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

template<class T>
void List<T>::Add(T x)
{
	Node<T> *temp = new Node<T>;
	temp->Next = NULL;
	temp->x = x;

	if (Head != NULL)
	{
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		temp->Prev = NULL;
		Head = Tail = temp;
	}
}

template<class T>
void  List<T>::Del()
{
	Node<T> *temp = Head->Next;
	delete Head;
	temp->Prev = NULL;
	Head = temp;
}

template<class T>
void List<T>::ShowLine()
{
	Node<T> *temp = Head;
	while (temp != NULL)
	{
		std::cout << temp->x << " ";
		temp = temp->Next;
	}
	std::cout << std::endl;
}

template<class T>
void List<T>::ShowCol()
{
	Node<T> *temp = Head;
	while (temp != NULL)
	{
		std::cout << temp->x <<std::endl;
		temp = temp->Next;
	}
	
}