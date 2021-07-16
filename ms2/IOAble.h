/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
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
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
using namespace std;
namespace sdds
{
    class IOAble
    {
    public:
    virtual ostream& csvWrite(std::ostream& ostr)const = 0;
    virtual istream& csvRead(std::istream& istr) = 0;
    virtual ostream& write(ostream& ostr)const = 0;
    virtual istream& read(istream& istr) = 0;
   virtual  ~IOAble() = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const IOAble&);
    std::istream& operator>>(std::istream& istr, IOAble&);
}
#endif
