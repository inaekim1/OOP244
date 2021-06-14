/* Workshop 3 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/02

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Food.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    void Food::setName(const char* name)
    {
        strnCpy(m_foodName, name, 30);

    }

    void Food::setEmpty()
    {
        m_foodName[0] = '\0';
        m_calNum = 0;
    }
    void Food::set(const char* name, int num, int time)
    {
        if (num < 0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            m_calNum = num;
            m_timeOfConsumption = time;

        }
    }
    bool Food::isValid()const
    {
        bool ret = false;
        if (calNum() != 0 && m_foodName[0] != 0 && m_timeOfConsumption != 0)
        {
            ret = true;
        }
        return ret;

    }
    int Food::time()const
    {
        return m_timeOfConsumption;
    }
    
    int Food::calNum()const
    {
        return m_calNum;
    }
    void Food::display()const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(30);
            cout.fill('.');
            cout.setf(ios::left);
            cout << m_foodName;
            cout.unsetf(ios::left);

            cout << " | ";
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << calNum();
            cout.unsetf(ios::right);
            cout << " | ";
            cout.width(10);
            cout.fill(' ');
            cout.setf(ios::left);
            switch (m_timeOfConsumption)
            {
            case 1:
                cout << "Breakfast";
                break;
            case 2:
                cout << "Lunch";
                break;
            case 3:
                cout << "Dinner";
                break;
            case 4:
                cout << "Snack";
                break;
                     default:
                             break;
            }
            cout.unsetf(ios::left);
            cout << " |" << endl;
        }
        else
        {
            cout << "| ";
            cout.width(33);
            cout.fill('x');
            cout.unsetf(ios::left);

            cout << " | ";
            cout.width(7);
            cout.fill('x');
            cout << " | ";
            cout.width(12);
            cout.fill('x');
            cout << " |" << endl;

        }

    }

}