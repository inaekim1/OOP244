#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow()
    {
        m_min = getTime();
        return *this;
    }
    Time::Time(unsigned int min)
    {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr)const
    {
        int hour{};
        int min{};

        hour = m_min / 60;
        min = m_min % 60;

        if (hour < 10)
        {
            ostr << "0";
            ostr << hour;
        }
        else
        {
            ostr << hour;
        }
        ostr << ":";
        if (min < 10)
        {
            ostr << "0";
            ostr << min;
        }
        else
        {
            ostr << min;
        }
      

        return ostr;
    }
    std::istream& Time::read(std::istream& istr)
    {
        int hour{};
        int min{};
        char ch{};
        istr >> hour >> ch >> min;
        if (hour < 0 || ch != ':' || min < 0)
        {
            istr.setstate(ios::failbit);
        }
        
        return istr;
    }
    Time& Time::operator-=(const Time& D)
    {
        int hour = m_min / 60;
        int hour2 = D.m_min / 60;
        if (hour < hour2)
        {
            m_min += 1440;
        }
        m_min -= D.m_min;

        return *this;
    }
    Time Time::operator-(const Time& D)const
    {
        Time t{};
        int hour = m_min / 60;
        int hour2 = D.m_min / 60;
        if (hour < hour2)
        {
            if (hour2 > 12 && hour2 < 24)
            {
                t.m_min = (m_min+1440) - D.m_min;

            }
            else if (hour2 > 24 && hour2 < 48 )
            {
                t.m_min = (m_min + 2880) - D.m_min;
            }
        }
         return t;

    }
    Time& Time::operator+=(const Time& D)
    {
        m_min += D.m_min;

        return *this;
    }
    Time Time::operator+(const Time& D)const
    {
        Time t;
        t.m_min = m_min + D.m_min;

        return t;
    }
    Time& Time::operator=(unsigned int val)
    {
        m_min = val;

        return *this;
    }
    Time& Time::operator *= (unsigned int val)
    {
        m_min *= val;

        return *this;
    }
    Time& Time::operator /= (unsigned int val)
    {
        m_min /= val;

        return *this;
    }
    Time Time::operator *(unsigned int val)const
    {
        Time t;
        t.m_min = m_min* val;

        return t;
    }
    Time Time::operator /(unsigned int val)const
    {
        m_min / val;

        return *this;
    }
    Time::operator unsigned int()const
    {
        return m_min;
    }
    Time::operator int()const
    {
        return m_min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        return D.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Time& D)
    {
        return D.read(istr);
    }
}