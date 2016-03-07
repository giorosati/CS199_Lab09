/*********************************************************************
** Program Filename: main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-06
** Description: File with main() for CS199_400 Lab 8
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>

#include "node.hpp"
#include "myLL.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void displayMenuOne();
void displayMenu();
int getInput();

int main()
{
	bool doneOne = false;
	bool done = false;
	int typeOfLL = 0;
	int choice = 0;
	int intIn = -1;
	double doubleIn = -1;
	string stringIn = "";

	cout << "This program allows testing of a linked list using a templated class" << endl;
	cout << "You can choose what type of data to use: int, double, or string." << endl;
	cout << endl;

	// display a menu and get user selection for what kind of data will be stored 
	// in the value data member of the node
	if (doneOne != true)
	{
		displayMenuOne();
		typeOfLL = getInput();
		switch (typeOfLL) {
		case 1:
			typeOfLL = 1;
			break;
		case 2:
			typeOfLL = 2;
			break;
		case 3:
			typeOfLL = 3;
			break;
		case 4:
			doneOne = true;
			break;
		default:
			std::cout << "Not a valid choice" << std::endl;
			break;
		}
	}

	if (typeOfLL == 1)			//begin code for the int linked list
	{
		myLL<int> list;			//create an int linked list

		while (done != true) {
			displayMenu();
			choice = getInput();
			switch (choice) {
			case 1:				//display the list
				list.displayList();
				break;
			case 2:				//add a node to the end of the list
				while (intIn < 0)
				{
					cout << "Enter a positive integer: ";
					cin.ignore();
					cin >> intIn;
					if (intIn < 0)
					{
						cout << "Invalid entry..." << endl;
						cout << endl;
					}
				}
				list.addValue(intIn);
				intIn = -1;		//reset intIn
				break;
			case 3:				//remove the last node
				list.removeLast();
				break;
			case 4:				//sort the list
				list.sort();
				break;
			case 5:				//search for a value in the list
				while (intIn < 0)
				{
					cout << "Enter a positive integer: ";
					cin.ignore();
					cin >> intIn;
					if (intIn < 0)
					{
						cout << "Invalid entry..." << endl;
						cout << endl;
					}
				}
				list.search(intIn);
				intIn = -1;		//reset intIn
				break;
			case 6:
				done = true;
				break;
			default:
				std::cout << "Not a valid choice" << std::endl;
				break;
			}		//end of switch
		}
	}	//end of int linked list code


	if (typeOfLL == 2)		//begin code for the double linked list
	{
		myLL<double> list;			//create an double linked list

		while (done != true) {
			displayMenu();
			choice = getInput();
			switch (choice) {
			case 1:				//display the list
				list.displayList();
				break;
			case 2:				//add a node to the end of the list
				while (doubleIn < 0)
				{
					cout << "Enter a positive double: ";
					cin.ignore();
					cin >> doubleIn;
					if (doubleIn < 0)
					{
						cout << "Invalid entry..." << endl;
						cout << endl;
					}
				}
				list.addValue(doubleIn);
				doubleIn = -1;		//reset doubleIn
				break;
			case 3:				//remove the last node
				list.removeLast();
				break;
			case 4:				//sort the list
				list.sort();
				break;
			case 5:				//search for a value in the list
				while (doubleIn < 0)
				{
					cout << "Enter a positive double: ";
					cin.ignore();
					cin >> doubleIn;
					if (doubleIn < 0)
					{
						cout << "Invalid entry..." << endl;
						cout << endl;
					}
				}
				list.search(doubleIn);
				doubleIn = -1;	//reset doubleIn
				break;
			case 6:
				done = true;
				break;
			default:
				std::cout << "Not a valid choice" << std::endl;
				break;
			}		//end of switch
		}
	}	//end of double linked list code


	if (typeOfLL == 3)			//begin code for the double linked list
	{
		myLL<string> list;			//create a string linked list

		while (done != true) {
			displayMenu();
			choice = getInput();
			switch (choice) {
			case 1:				//display the list
				list.displayList();
				break;
			case 2:				//add a node to the end of the list
				while (stringIn.length() < 1)
				{
					cout << "Please enter a string of characters. " << endl;
					cout << "Your string will end as of its first whitespace character." << endl;
					cout << "Enter your string: ";
					cin >> stringIn;
					cin.clear();
					cin.ignore(100, '\n');
					if (stringIn.length() < 1)
					{
						stringIn = "";
						cout << "Try again." << endl;
						cout << endl;
					}
				}
				cout << endl;
				list.addValue(stringIn);
				stringIn = "";		//reset stringIn
				break;
			case 3:				//remove the last node
				list.removeLast();
				break;
			case 4:				//sort the list
				list.sort();
				break;
			case 5:				//search for a value in the list
				while (stringIn.length() < 1)
				{
					cout << "Please enter a string of characters. " << endl;
					cout << "Your string will end as of its first whitespace character." << endl;
					cout << "Enter your string: ";
					cin >> stringIn;
					cin.clear();
					cin.ignore(100, '\n');
					if (stringIn.length() < 1)
					{
						stringIn = "";
						cout << "Try again." << endl;
						cout << endl;
					}
				}
				cout << endl;
				list.search(stringIn);
				stringIn = "";	//reset stringIn
				break;
			case 6:
				done = true;
				break;
			default:
				std::cout << "Not a valid choice" << std::endl;
				break;
			}		//end of switch
		}
	}	//end of double linked list section
}

//functions

void displayMenuOne()		//displays user choice for type of data
{
	cout << endl;
	cout << "Choose the type of value for the list" << endl;
	cout << "*************************" << endl;
	cout << "  1) Integer" << endl;
	cout << "  2) Double" << endl;
	cout << "  3) String" << endl;
	cout << "  4) Exit" << endl;
	cout << endl;
}

void displayMenu()		//displays user choices for the linked list
{
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "*************************" << endl;
	cout << "  1) Display the list" << endl;
	cout << "  2) Add a value to the list" << endl;
	cout << "  3) Remove the last value" << endl;
	cout << "  4) Sort the list" << endl;
	cout << "  5) Search for a value in the list" << endl;
	cout << "  6) Exit" << endl;
	cout << endl;
}

int getInput() {	//to collect user responses to menus
	int choice;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}