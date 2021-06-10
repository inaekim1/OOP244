#include <iostream>
#include "cstring.h"
#include "Item.h"
#define TAX_RATE 0.13;
using namespace std;
namespace sdds {
    void Item::setName(const char* name)
    {
        strnCpy(m_itemName, name, 20);
    }
    void Item::setEmpty()
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }
    void Item::set(const char* name, double price, bool taxed)
    {
        if (price < 0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;

        }
      
     
      
    }
    void Item::display()const
    {
       
        cout << "| ";
        if (isValid())
        {
           cout.width(20);
           cout.fill('.');
           cout.setf(ios::left);
           cout << m_itemName;
            cout.unsetf(ios::left);
            cout << " | ";
            cout.width(7);
            cout.fill(' ');
            cout << price();
            cout << " | ";
            if (m_taxed)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No ";
            }
            cout << " |" << endl;
       
        }
        else
        {
           cout.width(23);
           cout.fill('x');
           cout << " | ";
           cout.width(10);
           cout.fill('x');
           cout << " | ";
           cout.width(5);
           cout.fill('x');
           cout << " |" << endl;
        }

    }
    bool Item::isValid()const
    {
        bool ret = false;
        if (price() != 0.0 && m_itemName[0] != 0)
        {
            ret = true;
        }
        return ret;
    }
    double Item::price()const
    {
        return m_price;
    }
    double Item::tax()const
    {
        double taxed = m_price * 0.13;
        return m_taxed == true ? taxed : 0.0;
    }

}