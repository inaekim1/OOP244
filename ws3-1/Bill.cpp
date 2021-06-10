#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    double Bill::totalTax()const
    {
        /*int count = 0; */
        double totaltax = 0.0;
      /*  while (m_items[count].isValid())
        {
            totaltax += m_items[count].tax();
            count++;
        }*/
        for (int i = 0; i < m_noOfItems; i++)
        {
            totaltax += m_items[i].tax();
            
        }
        return totaltax;
    }
    double Bill::totalPrice()const
    {
        
        double totalprice = 0.0;
        /*int count = 0;
        while (m_items[count].isValid())
        {
            totalprice += m_items[count].price();
            count++;
        }*/
        for (int i = 0; i < m_noOfItems; i++)
        {
            totalprice += m_items[i].price();

        }
        return totalprice;
    }
    void Bill::Title()const
    {
        cout << "+--------------------------------------+" << endl;
        cout << "| ";
        cout.width(36);
        cout.fill(' ');
        cout.setf(ios::left);
        if (m_items->isValid())
        {
            cout << m_title;
        }
        else
        {
            cout << "Invalid Bill";
        }
        cout << " |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| ";
        cout.width(20);
        cout.fill(' ');
        cout << "Item Name";
        cout << " |";
        cout.width(6);
        cout.fill(' ');
        cout << " Price";
        cout << "   +" <<" Tax" << " |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
        cout.unsetf(ios::left);
    }
    void Bill::footer()const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.width(30);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << "Total Tax :";

            cout.width(6);
            cout.setf(ios::right);
            cout << totalTax();
            cout << " |" << endl;

            cout << "| ";
            cout.width(24);
            cout.setf(ios::right);
            cout << "Total Price :";
            cout << totalPrice() << " |" << endl;

            cout << "| ";
            cout.width(10);
            cout.setf(ios::right);
            cout << "Total After Tax:" << totalPrice() + totalTax() << " |" << endl;

        }
        else
        {
            cout << "| ";
            cout << "Invalid Bill";
            cout.width(36);
            cout.fill(' ');
            cout << " |";
        }
       
        cout << "+--------------------------------------+" << endl;
    }
    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }
    bool Bill::isValid()const
    {
        bool ret = false;
        int found = -1;
       
        if (m_title[0] != '\0' && m_items != nullptr)
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                if (m_items[i].isValid())
                {
                    found = 1;
                }
            }
        }
        if (found == 1)
        {
            ret = true;
        }
        return ret;
      
    }
    void Bill::init(const char* title, int noOfItems)
    {
        m_noOfItems = noOfItems;
        m_itemsAdded = 0;
        strCpy(m_title, title);
        m_items = new Item[m_noOfItems];
        for (int  i = 0; i < m_noOfItems; i++)
        {
            m_items[i].setEmpty();
        }

    }
    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool ret = false;

        if (m_itemsAdded < m_noOfItems )
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            ret = true;
        }
        
        return ret;
    }
    void Bill::display()const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }
    void Bill::deallocate()
    {
        delete[] m_items;
        

    }

}