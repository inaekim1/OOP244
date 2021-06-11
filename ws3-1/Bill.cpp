/* Workshop 3 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/02

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    double Bill::totalTax()const
    {
        double totaltax = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            totaltax += m_items[i].tax();
            
        }
        return totaltax;
    }
    double Bill::totalPrice()const
    {
        double totalprice = 0.0;
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
        if (isValid())
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
        
    }
    void Bill::footer()const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "| ";

            cout.width(26);
            cout << "Total Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout << fixed << setprecision(2) << totalTax();
            cout << " |" << endl;

            cout << "| ";

            cout.width(26);
            cout << "Total Price: ";
            cout.width(10);
            cout.setf(ios::right);
            cout << fixed << setprecision(2) << totalPrice() << " |" << endl;

            
            cout << "| ";
            cout.width(26);
            cout << "Total After Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout << fixed << setprecision(2)<< totalPrice() + totalTax() << " |" << endl;
            cout.unsetf(ios::right);
            cout << "+--------------------------------------+" << endl;
        }
        else
        {
           
            cout << "| ";
            cout << "Invalid Bill";
            cout.width(26);
            cout.fill(' ');
            cout << " |" << endl;
            cout << "+--------------------------------------+" << endl;
        }
       
      
    }
    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }
    bool Bill::isValid()const
    {
        bool ret = false;
        int found = 0;
       
        if (m_title[0] != '\0' && m_items != nullptr)
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                if (m_items[i].isValid())
                {
                    found++;
                }
            }
        }
        if (found == m_noOfItems)
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