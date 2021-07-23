/* Workshop 8 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/21
Section : OOP244 NBB

Second submission : deleted commented codes
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include "LblShape.h"
namespace sdds
{
    class Rectangle : public LblShape
    {
        int m_width;
        int m_height;

    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void setEmpty();
        void getSpecs(std::istream&);
        void draw(std::ostream&)const;
    };

}
#endif // !SDDS_RECTANGLE_H

