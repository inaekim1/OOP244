/* Workshop 8 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/21
Section : OOP244 NBB

Second submission : deleted commented codes
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include "Shape.h"
namespace sdds
{
    class LblShape :
        public Shape
    {
        char* m_label{};

    protected:
       char* label()const;
    public:
        LblShape();
        LblShape(const char* label);
       virtual ~LblShape();
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        void getSpecs(std::istream&);
    };
}
#endif


