#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
#include "Time.h"
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
        cout << "General Hospital Pre-Triage Application" << endl;
        cout << "1- Register" << endl;
        cout << "2- Admit" << endl;
        cout << "0- Exit" << endl;

    }
    int& Menu::operator>>(int& Selection)
    {
        const char* error = "Invalid option ";
        display();
        Selection = getInt(0, m_noOfSel ,">", error);
        switch (Selection)
        {
        case 0:
            cout << "goodbye!" << endl;
        case 1:
            cout << "option one selected" << endl;
        case 2:
            cout << "option two selected" << endl;
        case 3:
            cout << "option three selected " << endl;
        default: cout << "invalid option!" << endl;
            break;
        }
        return Selection;
    }





}