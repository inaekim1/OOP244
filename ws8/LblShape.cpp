/* Workshop 8 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/21
Section : OOP244 NBB

Second submission : deleted commented codes
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds
{
    LblShape::LblShape()
    {
        if (m_label != nullptr)
        {
            delete[] m_label;

        }
        m_label = nullptr;
    }
    LblShape::LblShape( const char* label)
    {
        if (m_label != nullptr)
        {
            delete[] m_label;

        }
        m_label = new char[strlen(label)+1]; 
        strcpy(m_label, label);
    

    }
    char* LblShape::label()const
    {
        return m_label;
    }
    LblShape::~LblShape()
    {
            delete[] m_label;
            m_label = nullptr;
       
    }
    void  LblShape::getSpecs(std::istream& is)
    {
     
        char str[100]{};
        is.getline(str,100,',');
        delete[] m_label;
        m_label = nullptr;
        m_label = new char[strlen(str)+1];
        strcpy(m_label, str);

        
    }
}
