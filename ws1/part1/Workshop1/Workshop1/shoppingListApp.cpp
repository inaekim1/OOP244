/*
    Workshop 1 part 1
    Name : Inae Kim
    Seneca email : ikim36@myseneca.ca
    Seneca ID : 132329202
    Section : OOP244 NBB
*/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"
using namespace std;
using namespace sdds;

const bool APP_OS_WINDOWS = false;

int listMenu();

int listMenu()
{
    cout << "-->>> My Shopping List <<<--" << endl;
    displayList();
    cout << "----------------------------" << endl
        << "1- Toggle bought Item" << endl
        << "2- Add Shopping Item" << endl
        << "3- Remove Shopping Item" << endl
        << "4- Remove bought Items" << endl
        << "5- Clear List" << endl
        << "0- Exit" << endl << "> ";
    return readInt(0, 5);
}

int main()
{
    bool done = false;
    loadList();
    while (!done)
    {
        system(APP_OS_WINDOWS ? "cls" : "clear");
        switch (listMenu())
        {
        case 1:
            toggleBought();
            break;
        case 2:
            addItemToList();
            break;
        case 3:
            removeItemfromList();
            break;
        case 4:
            removeBoughtItems();
            break;
        case 5:
            clearList();
            break;
        default:
            done = true;
        }
    }
    saveList();
    return 0;
}