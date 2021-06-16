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

    }
 
    Canister::Canister(const char* contentName)
    {
        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter, const char* contentName)
    {
        /*
        The smallest Canister can have a height and diameter of 10.0 by 10.0 centimetres and the largest one can be 40 by 30 respectively.*/
        if (height >= 10.0 || height <= 40.0 || diameter >= 10.0 || diameter <= 30.0 )
        {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0;
            setName(contentName);
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
        if (contentName == nullptr)
        {
            m_usable = false;
        }
        else if (isEmpty())
        {
            setName(contentName);
        }
        else if(!strCmp(contentName, m_contentName))
        {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(double quantity)
    {
        if (m_usable && quantity > 0)
        {
            if (quantity + volume() <= capacity())
            {
                m_contentVolume += quantity;
            }
            else
            {
                m_usable = false;
            }
        }
        return *this;
  
    }
    Canister& Canister::pour(Canister&)
    {
        setContent(m_contentName);
        if (volume() > (capacity() - volume()))
        {
            m_contentVolume -= (capacity() - volume());

        }
        else
        {
            pour(m_contentVolume);
            m_contentVolume = 0;
        }
        return *this;
    }
    double Canister::volume()const
    {
        return m_contentVolume;
    }
    std::ostream& Canister::display()const
    {
        cout.width(7);
        cout.fill(' ');
        cout << capacity();
        cout << "cc (";
        cout << m_height;
        cout << "x";
        cout << m_diameter;
        cout << ") Canister";

        if (m_usable)
        {
            cout << " of Unusable content, discard!" << endl;
        }
        else if (m_contentName != nullptr)
        {
            cout << " of ";
            cout.width(7);
            cout.fill(' ');
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