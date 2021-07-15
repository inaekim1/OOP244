/* Workshop 7 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/14
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    MotorVehicle::MotorVehicle()
    {

    }

    MotorVehicle::MotorVehicle(const char licensePlate[], int year)
    {
        strCpy(m_license, licensePlate);
        m_year = year;
        strCpy(m_address, "Factory");
      
    }
    void MotorVehicle::moveTo(const char* address)
    {
        cout.setf(ios::right);
        cout << "|";
        cout.width(8);
        cout << m_license << "|";
        cout << " |";
        cout.width(20);
        cout << m_address;
        cout << " ---> ";
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout.width(20);
        cout << address;
        cout << "|" << endl;
        if (strCmp(m_address, address))
        {
            strCpy(m_address, address);
        }
        cout.unsetf(ios::left);

      
    }
    std::ostream& MotorVehicle::write(std::ostream& os)const
    {
        os << "| " << m_year << " | " << m_license << " | " << m_address;

        return os;
    }
    std::istream& MotorVehicle::read(std::istream& in)
    {
            cout << "Built year: ";
            in >> m_year;
            cout << "License plate: ";
            in >> m_license;
            cout << "Current location: ";
            in >> m_address;

            return in;

    }
    std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& MV)
    {
        return MV.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, MotorVehicle& MV)
    {
        return MV.read(istr);
    }

}