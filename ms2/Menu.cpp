#include <iostream>
#include <cstring>
#include "Menu.h"
using namespace std;
namespace sdds
{
    Menu::Menu(const char* MenuContent, int NoOfSelections)
    {
        m_noOfSel = NoOfSelections;
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);
    }
    virtual Menu::~Menu()
    {

    }
    void Menu::display()const
    {

    }


}