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
#include "Shape.h"
#include "Line.h"
using namespace std;
namespace sdds
{
    Line::Line() : LblShape()
    {
        m_length = 0;
    }
    Line::Line(const char* str, int length) : LblShape(str)
    {
        m_length = length;
    }
    void Line::getSpecs(std::istream& is)
    {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }
    void Line::draw(std::ostream& os)const
    {

        if (m_length > 0 && label() != nullptr)
        {
            os << label() << endl;
            for (int i = 0; i < m_length; i++)
            {
                os << "=";
            }
        }
    }
}
