/* Workshop 8 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/21
Section : OOP244 NBB

Second submission : deleted commented codes
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds
{
    Rectangle::Rectangle() : LblShape()
    {
        m_width = 0;
        m_height = 0;
    }
    Rectangle::Rectangle(const char* _label, int width, int height) : LblShape(_label)
    {
   
        m_width = width;
        m_height = height;
        int wid = strlen(label()) + 2;
        if (m_height < 3 || m_width < wid)
        {
            setEmpty();
        }
 

    }
    void Rectangle::setEmpty()
    {
        m_height = 0;
        m_width = 0;
    }
    void Rectangle::getSpecs(std::istream& is)
    {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
    }
    void Rectangle::draw(std::ostream& os)const
    {
        
        int wid = m_width - 2;
        if (m_width != 0 && m_height != 0)
        {
            os << "+";
            for (int i = 0; i < wid; i++)
            {
                os << "-";
            }
            os << "+" << endl;
            for (int i = 0; i < m_height-2; i++)
            {
                os << "|";
                if (i == 0)
                {
                    os.setf(ios::left);
                    
                    os.width(wid);
                    os.fill(' ');
                    os << label();
                    os.unsetf(ios::left);
                    os << "|" << endl;
                }
                else
                {
                    os.width(wid+1);
                    os.fill(' ');
                    os << " |" << endl;
                }
                
            }

            os << "+";
            for (int i = 0; i < wid; i++)
            {
                os << "-";
            }
            os.fill('-');
            os << "+";

        }
    }
}
