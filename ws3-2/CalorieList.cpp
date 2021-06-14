/* Workshop 3 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/14
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include "CalorieList.h"
using namespace std;
namespace sdds
{
    void CalorieList::Title()const
    {
        cout << "+----------------------------------------------------+" << endl;
        cout << "| ";
       
        if (isValid())
        {
            cout << " Daily Calorie Consumption";
            cout.width(26);
            cout.fill(' ');
        }
        else
        {
            cout << "Invalid Calorie Consumption list";
            cout.width(20);
            cout.fill(' ');
        }
        
        cout << " |" << endl;

        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| " << "Food name";
        cout.width(24);
        cout.fill(' ');
        cout << " | " << "Cals" << " | ";
        cout << "When";
        cout.width(8);
        cout.fill(' ');
        cout << " |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;

    }
    void CalorieList::footer()const
    {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "| ";

            cout.width(29);
            cout << "Total Calories for today: ";
            cout.width(8);
            cout.fill(' ');
            cout << totalCalorie();
            cout << " | ";
            cout.width(12);
            cout.fill(' ');
            cout<< " |" << endl;
           
        }
        else
        {
            cout << "| ";
            cout.width(35);
            cout.fill(' ');
            cout << "Invalid Calorie Consumption list";
            cout.setf(ios::right);
            cout.width(17);
            cout.fill(' ');
            cout.unsetf(ios::right);
            cout << " |" << endl;
            
        }
      
        cout << "+----------------------------------------------------+" << endl;
        

    }
    void CalorieList::setEmpty()
    {
        foods = nullptr;
    }
    bool CalorieList::isValid()const
    {
        bool ret = false;
        int found = 0;

        if (foods != nullptr)
        {
            for (int i = 0; i < m_noOfFood; i++)
            {
                if (foods[i].isValid())
                {
                    found++;
                }
            }

        }
        if (found == m_noOfFood)
        {
            ret = true;
        }
        return ret;
    }


    int CalorieList::totalCalorie()const
    {
        int totalCal = 0;
        for (int i = 0; i < m_noOfFood; i++)
        {
            totalCal += foods[i].calNum();

        }
        return totalCal;
    }


    void CalorieList::init(int size)
    {
        m_noOfFood = size;
        m_foodAdded = 0;
        foods = new Food[size];
        for (int i = 0; i < m_noOfFood; i++)
        {
            foods[i].setEmpty();
        }
    }

    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        bool ret = false;

        if (m_foodAdded < m_noOfFood)
        {
            foods[m_foodAdded].set(item_name, calories, when);
            m_foodAdded++;
            ret = true;
        }

        return ret;
    }

    void CalorieList::display()const
    {
        Title();
        for (int  i = 0; i < m_noOfFood; i++)
        {
            foods[i].display();
        }
        footer();
    }

    void CalorieList::deallocate()
    {
        delete[] foods;
    }

}