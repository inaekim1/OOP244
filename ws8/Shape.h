/* Workshop 8 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/21
Section : OOP244 NBB

Second submission : deleted commented codes
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds
{
    class Shape
    {
    public:
        virtual void getSpecs(std::istream&) = 0;
        virtual void draw(std::ostream&)const = 0;
        virtual ~Shape() = 0;

    };
    std::istream& operator>>(std::istream&, Shape&);
    std::ostream& operator<<(std::ostream&, const Shape&);

}
#endif // !SDDS_SHAPE_H




