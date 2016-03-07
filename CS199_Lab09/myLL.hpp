/*********************************************************************
** Program Filename: myLL.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-06
** Description: myLL class header and implementation - CS199_400 Lab09
*********************************************************************/

//includes
#include "node.hpp"
#include <cstdlib>
#include <iostream>

//usings
using std::cout;
using std::endl;
using std::cin;


#ifndef MYLL_HPP
#define MYLL_HPP

template <typename T>
class myLL
{
private:
	Node<T>* head;

public:
	myLL();					//default constructor
	myLL(T valueIn);		//constructor
	~myLL();				//deconstructor

	//void displayList(Node* &head);
	void displayList();
	//Node* findLast(Node* &head);
	Node<T>* findLast();
	//void addValue(Node* &head, T valueIn);
	void addValue(T valueIn);
	//void removeLast(Node* &head);
	void removeLast();
	//void sort(Node* &head);
	void sort();
	//Node* search(Node* &head, T searchValue);
	void search(T searchValue);
};

#endif

template <typename T>
myLL<T>::myLL()
{
	head = NULL;
}

template <typename T>
myLL<T>::myLL(T valueIn)
{
	this->head = new Node<T>;
	this->value = valueIn;
}

template <typename T>
myLL<T>::~myLL()
{
	//cout << "deconstructor has run" << endl;
}

template <typename T>
///void myLL<T>::displayList(Node* &head)
void myLL<T>::displayList()
{
	if (head == NULL)
	{
		cout << "There are no items in the list." << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		Node<T>* tempNode = head;
		cout << tempNode->value << endl;	//outputs head nodes value
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			cout << tempNode->value << endl;//outputs nodes after head 
		}
		cout << endl;
	}
}

template <typename T>
//void myLL<T>::addValue(Node* &head, T valueIn)
void myLL<T>::addValue(T valueIn)
{
	if (head == NULL)		//case where no nodes exist
	{
		head = new Node<T>;
		head->value = valueIn;
		head->prev = NULL;
		head->next = NULL;
		cout << endl;
	}
	else					//adds a node to the end of the list
	{
		Node<T>* lastNode = findLast();
		lastNode->next = new Node<T>;
		lastNode->next->prev = lastNode;
		lastNode->next->value = valueIn;
		lastNode->next->next = NULL;
		cout << endl;
	}
}

template <typename T>
void myLL<T>::removeLast()
//void myLL<T>::removeLast(Node* &head)	//removes the last node, if any
{
	if (head == NULL)
	{
		cout << "You cannot remove an element from an empty list!" << endl;
		cout << endl;
	}
	else
	{
		Node<T>* lastNode = findLast();			//find the last node
		if (lastNode->prev == NULL) head = NULL;	//if it's the first node, set head to NULL
		if (lastNode->prev != NULL)
		{
			lastNode->prev->next = NULL;	//sets "next" on the second to last node to NULL
		}
		delete lastNode;					//deletes the last node
	}
	cout << endl;
}

template <typename T>
//Node* myLL<T>::findLast(Node* &head)
Node<T>* myLL<T>::findLast()
{
	Node<T>* tempNode = head;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	return tempNode;
}

template <typename T>
//void myLL<T>::sort(Node* &head)
void myLL<T>::sort()
{
	Node<T>* tempNode = head;
	T tempT = NULL;
	bool swap;
	do
	{
		swap = false;
		{
			if (tempNode->value > tempNode->next->value)
			{
				tempT = tempNode->value;
				tempNode->value = tempNode->next->value;
				tempNode->next->value = tempT;
				swap = true;
			}
			tempNode = tempNode->next;
		}
	} while (tempNode->next != NULL);
}

template <typename T>
//void myLL<T>::search(Node* &head, T searchValue)
void myLL<T>::search(T searchValue)
{
	Node<T>* tempNode = head;
	bool found = false;
	while (tempNode->next != NULL && found == false)
	{
		if (tempNode->value = searchValue)
		{
			found = true;
		}
		else tempNode = tempNode->next;
	}
	if (tempNode->next == NULL)	//check the last node
	{
		if (tempNode->value == searchValue)
		{
			found = true;
		}
	}
	if (found == true) cout << searchValue << " was found in the list." << endl;
	else cout << searchValue << " was NOT found in the list." << endl;
}
