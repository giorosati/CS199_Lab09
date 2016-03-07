/*********************************************************************
** Program Filename: node.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-06
** Description: node struct header file CS199_400 Lab 9
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node
{
	T value;
	Node* prev;
	Node* next;
};

#endif
