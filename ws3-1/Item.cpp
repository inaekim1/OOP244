#include <iostream>
#include "cstring.h"
#include "Item.h"
#define TAX_RATE 0.13;
using namespace std;
namespace sdds {
    void Item::setName(const char* name)
    {
        name = m_itemName;
    }
    void Item::setEmpty()
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }
    void Item::set(const char* name, double price, bool taxed)
    {
        strCpy(m_itemName, name);
        m_price = price;
        m_taxed = taxed;
        if (m_price < 0 || m_itemName == nullptr)
        {
            setEmpty();
        }
    }
    void Item::display()const
    {
       
        cout << right << "| ";
        if (isValid())
        {
            cout << m_itemName;
            for (int i = 0; i < 20 -strLen(m_itemName); i++)
            {

                cout << ".";

            }
        }
        else
        {
            for (int i = 0; i < 20; i++)
            {

                cout << "x";

            }

        }
        
          cout << left << " |";
          for (int i = 0; i < 7; i++)
          {
              cout << " ";
          }
          cout << left << " | ";
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
    bool Item::isValid()const
    {
        bool ret = false;
        if (m_price != 0.0 && m_itemName[0] != 0)
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