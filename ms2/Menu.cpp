/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds
{
    Menu::Menu(const char* MenuContent, int NoOfSelections)
    {
        m_noOfSel = NoOfSelections;
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);
    }
   Menu::~Menu()
    {
        delete[] m_text;

    }
    void Menu::display()const
    {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }
    int& Menu::operator>>(int& Selection)
    {
        const char* error = "Invalid option ";
        display();
        Selection = getInt(0, m_noOfSel ,"> ", error, true);

        return Selection;
    }
    Menu::Menu(const Menu& M )
    {
        delete[] m_text;
        m_noOfSel = 0;
        if (M.m_text != nullptr)
        {
            m_text = new char[strlen(M.m_text) + 1];
            strcpy(m_text, M.m_text);
            m_noOfSel = M.m_noOfSel;
        }
    }

}