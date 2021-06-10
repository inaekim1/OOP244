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
        /*Sets the Item to a recognizable safe Empty State. Do this by setting the price to an impossible value like 0.0 and setting the m_itemName to a blank string (first character set to null).*/
        m_price = 0.0;
        m_itemName[0] = '\0';
    }
    void Item::set(const char* name, double price, bool taxed)
    {
        setName(name);
        m_price = price;
        m_taxed = taxed;
        if (price < 0 || name == NULL )
        {
            setEmpty();
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
            cout.fill(' ');
            cout.unsetf(ios::left);
            //for (int i = 0; i < 20 -strLen(m_itemName); i++)
            //{
            //    cout << ".";
            //}
        }
        else
        {
           cout.width(20);
           cout.fill('x');
           cout << 'x';
        }
        
          cout  << " |";
          for (int i = 0; i < 4; i++)
          {
              cout << " ";
          }
          cout << price();
          cout  << " |";
          if (tax() != 0.0)
          {
              cout << "Yes";
          }
          else
          {
              cout << "No ";
          }
          cout << " |" << endl;

    }
    bool Item::isValid()const
    {
        bool ret = false;
        if (m_price > 0.0 && m_itemName[0] != 0)
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