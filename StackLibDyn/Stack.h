#pragma once
#include "pch.h"
#include<iostream>

template< class S>

class Stack
{
private:
	S* pile;
	int sommet;
	int capacity;
public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void Empiler(S);
	S Depiler();
	int Size() const;
	void afficher() const;
};




template<class S>
inline Stack<S>::Stack() :sommet(0), capacity(3)
{
	this->pile = new S[3];
}

template<class S>
Stack<S>::~Stack()
{
	delete[] pile;
}

template<class S>
inline bool Stack<S>::isEmpty()
{
	return (sommet == 0);
}

template<class S>
inline bool Stack<S>::isFull()
{
	return (sommet == capacity);
}

template<class S>
inline void Stack<S>::Empiler(S val)
{
	int k = 0;

	if (isFull())
	{
		S* Temp = new S[this->capacity];
		this->capacity *= 2;
		S* tab = new S[this->capacity];

		for (int i = this->sommet - 1; i >= 0; i--)
		{

			Temp[k++] = pile[i];

		}

		k = 0;
		for (int j = sommet - 1; j >= 0; j--)
		{
			tab[k++] = Temp[j];
		}

		tab[this->sommet++] = val;
		delete[] Temp;

		pile = tab;

	}
	else
		this->pile[this->sommet++] = val;
}



template<class S>
inline S Stack<S>::Depiler()
{
	if (isEmpty()) {
		std::cout << "Pile vide !" << std::endl;  // Gestion de l'erreur
		return -1;
	}

	return pile[--sommet];
}

template<class S>
inline int Stack<S>::Size() const
{
	return sommet;
}

template<class S>
inline void Stack<S>::afficher() const
{

	for (int i = sommet - 1; i >= 0; i--)
	{
		std::cout << pile[i] << " " << std::endl;
	}


}