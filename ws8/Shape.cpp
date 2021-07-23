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
namespace sdds
{
    Shape::~Shape()
    {

    }
    std::istream& operator>>(std::istream& is, Shape& S)
    {
        S.getSpecs(is);

        return is;
    }
    std::ostream& operator<<(std::ostream& os, const Shape& S)
    {
        S.draw(os);

        return os;
    }
}
