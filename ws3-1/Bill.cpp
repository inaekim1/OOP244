#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    double Bill::totalTax()const
    {
        int count = 0; 
        double totaltax = 0.0;
        while (m_items[count].isValid())
        {
            totaltax += m_items[count].tax();
            count++;
        }
        return totaltax;
    }
    double Bill::totalPrice()const
    {
        int count = 0;
        double totalprice = 0.0;
        while (m_items[count].isValid())
        {
            totalprice += m_items[count].price();
            count++;
        }
        return totalprice;
    }
    void Bill::Title()const
    {
        cout << "+--------------------------------------+" << endl;
        cout << "| ";
        if (isValid())
        {
            cout << m_title;
        }
        else
        {
            cout << "Invalid Bill";
        }
        for (int i = 0; i < 36 - strLen(m_title); i++)
        {
            cout << " ";
        }
        cout << " |" << endl;
        
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| " << "Item Name";
        for (int i = 0; i < 12; i++)
        {
            cout << " ";
        }
        cout << "| " << "Price   | Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }
    void Bill::footer()const
    {
        cout << "+----------------------+---------+-----+" << endl;
        cout << " |              Total Tax:       " << totalTax() << " |" << endl;
        cout << " |            Total Price:       " << totalPrice() << " |" << endl;
        cout << " |          Total After Tax:      " << totalPrice() + totalTax() << " |" << endl;
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

    }
    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        int count = 0;
        bool ret = false;
        while (m_items[count].isValid())
        {
            count++;
        }
        if (m_itemsAdded < count )
        {
            m_items->set(item_name, price, taxed);
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