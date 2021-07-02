/* Workshop 5 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/30
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>
namespace sdds
{
    class Mark
    {
        int m_grade;
        double m_scale{};
        char m_symbol{};
        bool valid;

    public: 
        void setEmpty();
        Mark();
        Mark(int);
        bool  isValid();
        operator int();
        operator double();
        operator char();
        Mark& operator+=(int);
        Mark& operator=(int);
        ~Mark();
        
    };
    int operator+=(int& ,Mark&);
}
#endif // !
