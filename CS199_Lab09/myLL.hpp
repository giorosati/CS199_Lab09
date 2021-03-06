/*********************************************************************
** Program Filename: myLL.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-06
** Description: myLL class header and implementation - CS199_400 Lab09
** This linked list class was tested and works with int, double, and string
** data types.
*********************************************************************/

//includes
#include "node.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

//usings
using std::cout;
using std::endl;
using std::cin;
using std::string;

#ifndef MYLL_HPP
#define MYLL_HPP

template <typename T>
class myLL
{
private:
	Node<T>* head;

public:
	myLL();						//default constructor
	~myLL();					//deconstructor
	void displayList();			//display the list
	Node<T>* findLast();		//finds and returns the last node's pointer
	void addValue(T valueIn);	//adds a node to the end of the list
	void removeLast();			//removes the last node
	void sort();				//sorts the list
	void search(T searchValue);	//searches the list for a user entered value
};

#endif

//default constructor
template <typename T>
myLL<T>::myLL()
{
	head = NULL;
}

//deconstructor
template <typename T>
myLL<T>::~myLL()
{
	//cout << "deconstructor has run" << endl;
}

//displays the list
template <typename T>
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

//adds a node to the end of the list
template <typename T>
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

//removes the last node
template <typename T>
void myLL<T>::removeLast()
//removes the last node, if any
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

//finds and returns the last node's pointer
template <typename T>
Node<T>* myLL<T>::findLast()
{
	Node<T>* tempNode = head;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	return tempNode;
}

//sorts the list
template <typename T>
void myLL<T>::sort()
{
	if (head == NULL) cout << "List is empty - no elements to sort." << endl;
	else if (head->next == NULL) cout << "Only one item in the list." << endl;
	else
	{
		Node<T>* tempNode;
		T tempValue;
		bool swap;
		do
		{
			tempNode = head;
			swap = false;
			do
			{
				if (tempNode->value > tempNode->next->value)
				{
					tempValue = tempNode->value;
					tempNode->value = tempNode->next->value;
					tempNode->next->value = tempValue;
					swap = true;
				}
				if (tempNode->next != NULL) tempNode = tempNode->next;
			} while (tempNode->next != NULL);
		} while (swap);
	}
}

//searches the list for a user entered value
template <typename T>
void myLL<T>::search(T searchValue)
{
	if (head == NULL) cout << "List is empty - no elements to search." << endl;
	else
	{
		Node<T>* tempNode = head;
		bool found = false;
		do
		{
			if (tempNode->value == searchValue)
			{
				found = true;
			}
			if (tempNode->next != NULL) tempNode = tempNode->next;
		} while (tempNode->next != NULL && found == false);

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
}