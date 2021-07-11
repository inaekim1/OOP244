/* Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.h
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2020/7/4  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
using namespace std;
namespace sdds
{
    class IOAble
    {
    ostream& csvWrite(std::ostream& ostr)const;
    istream& csvRead(std::istream& istr);
    ostream& write(ostream& ostr)const;
    istream& read(istream& istr);
    virtual ~IOAble();
    };
    std::ostream& operator<<(std::ostream& ostr, const IOAble&);
    std::istream& operator>>(std::istream& istr, IOAble&);
}
#endif
