/* Workshop 4 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/02
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

    const double PI = 3.14159265;

    
    Canister::Canister()
    {
        setToDefault();
    }
 
    Canister::Canister(const char* contentName)
    {
        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter, const char* contentName)
    {

        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0)
        {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0;
            if (contentName != NULL)
            {
                setName(contentName);
            }
            else
            {
                m_contentName = nullptr;
            }
        }
        else
        {
            m_usable = false;
        }
       
    }
    
    
    void Canister::setToDefault()
    {
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    void Canister::setName(const char* Cstr)
    {
        if (Cstr != nullptr && m_usable)
        {
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }
    bool Canister::isEmpty()const
    {
        bool ret = false;
        if (m_contentVolume < 0.00001)
        {
            ret = true;
        }
        return ret;
    }
    bool Canister::hasSameContent(const Canister& C)const
    {
        bool ret = false;
        if ( m_contentName != nullptr && C.m_contentName != nullptr && (strCmp(m_contentName, C.m_contentName)) == 0)
        {
            ret = true;
        } 
        return ret;
    }

    Canister& Canister::setContent(const char* contentName)
    {
        if (contentName == NULL)
        {
            m_usable = false;
        }
        else if (isEmpty())
        {
            setName(contentName);
        }
        else if((strCmp(contentName, m_contentName)) != 0)
        {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(double quantity)
    {
        if (quantity > 0 && quantity + volume() <= capacity())
        {
            m_contentVolume += quantity;
        }
         else
            {
                m_usable = false;
            }

        return *this;
  
    }
    Canister& Canister::pour(Canister& C)
    {
        setContent(C.m_contentName);
        if (C.volume() > (capacity() - volume()))
        {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();

        }
        else
        {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }
    double Canister::volume()const
    {
        return m_contentVolume;
    }
    std::ostream& Canister::display()const
    {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout.fill(' ');
        cout << capacity();
        cout << "cc (";
        cout << m_height;
        cout << "x";
        cout << m_diameter;
        cout << ") Canister";

        if (!m_usable)
        {
            cout << " of Unusable content, discard!";
            
        }
        else if (m_contentName != NULL)
        {
            cout << " of ";
            cout.width(7);
            cout.fill(' ');
         
            cout << volume();
            cout << "cc  ";
            cout << m_contentName;
        }
        return cout;
    }
    double Canister::capacity()const
    {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }
    void Canister::clear()
    {
        if (!m_usable)
        {
            delete[] m_contentName;
            m_contentName = nullptr;
            m_contentVolume = 0.0;
            m_usable = true;
        }
      
    }
    Canister::~Canister()
    {
        delete[] m_contentName;
    }

   
}