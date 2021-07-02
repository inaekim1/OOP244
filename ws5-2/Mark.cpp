/* Workshop 5 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/30
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 


#include "Mark.h"
using namespace std;
namespace sdds
{
    void Mark::setEmpty()
    {
        m_grade = 0;
        valid = true;
    }

    Mark::Mark()
    {
        setEmpty();

    }
    Mark::Mark(int value)
    {
        setEmpty();
        if (value >= 0 && value <= 100)
        {
            m_grade = value;
           
        }
        else
        {
            valid = false;
        }
    }
    bool  Mark::isValid()
    {
        return valid;
    }
    Mark::operator int()
    {
        if (!valid)
        {
            m_grade = 0;
        }
        return m_grade;
    }
    Mark:: operator double()
    {
        if (m_grade >= 0 && m_grade < 50)
        {
            m_scale = 0.0;
        }
        else if (m_grade >= 50 && m_grade < 60)
        {
            m_scale = 1.0;
        }
        else if (m_grade >= 60 && m_grade < 70)
        {
            m_scale = 2.0;
        }
        else if (m_grade >= 70 && m_grade < 80 )
        {
            m_scale = 3.0;
        }
        else if (m_grade >= 80 && m_grade <= 100 )
        {
            m_scale = 4.0;
        }
        else
        {
            m_scale = 0;
        }
        return m_scale;
    }
    Mark::operator char()
    {
        if (valid)
        {
            if (m_grade >= 0 && m_grade < 50)
            {
                m_symbol = 'F';
            }
            else if (m_grade >= 50 && m_grade < 60)
            {
                m_symbol = 'D';
            }
            else if (m_grade >= 60 && m_grade < 70)
            {
                m_symbol = 'C';
            }
            else if (m_grade >= 70 && m_grade < 80)
            {
                m_symbol = 'B';
            }
            else
            {
                m_symbol = 'A';
            }
        }
        else
        {
            m_symbol = 'X';
        }
        return m_symbol;
        
    }
    Mark& Mark::operator+=(int value)
    {
        if (valid && (m_grade + value) <= 100 && (m_grade + value) >= 0)
        {
            m_grade += value;
        }
        else
        {
            valid = false;
            m_grade = 0;
        }
        
        return *this;
    }
    Mark& Mark::operator=(int value)
    {
        m_grade = value;
        if (m_grade >= 0 && m_grade <= 100)
        {
            valid = true;
        }
        else
        {
            m_grade = 0;
            valid = false;
        }
        return *this;
    }
 
    Mark::~Mark()
    {

    }

    int operator+=(int& left, Mark& right)
    {
        if (right.isValid())
        {
            left += right.operator int();
        }
        return left;
    }



}