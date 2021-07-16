/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "IOAble.h"
using namespace std;
namespace sdds
{
    IOAble::~IOAble()
    {

    }

    std::ostream& operator<<(std::ostream& ostr, const IOAble& IO)
    {
        return IO.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, IOAble& IO)
    {
        return IO.read(istr);
    }
}
