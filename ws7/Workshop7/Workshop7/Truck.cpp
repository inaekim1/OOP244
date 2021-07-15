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
#include "Truck.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
    Truck::Truck(const char licensePlate[], int year, double capacity, const char address[]) : MotorVehicle(licensePlate, year)
    {
        m_current_load_in_kg = 0;
        m_capacity_in_kg = capacity;
        moveTo(address);

    }
    bool  Truck::addCargo(double cargo)
    {
        double old{};
        old = m_current_load_in_kg;
        if (m_current_load_in_kg + cargo <= m_capacity_in_kg)
        {
            m_current_load_in_kg += cargo;
        }
        else
        {
            m_current_load_in_kg = m_capacity_in_kg;
        }


        return old != m_current_load_in_kg;
    }
    bool  Truck::unloadCargo()
    {
        bool ret = false;
        if (m_current_load_in_kg != 0)
        {
            ret = true;
        }
       m_current_load_in_kg = 0;

        return ret;
    }
    std::ostream& Truck::write(std::ostream& os)
    {
        MotorVehicle::write(os);
        os << " | " << m_current_load_in_kg << "/" << m_capacity_in_kg;

        return os;

    }
    std::istream& Truck::read(std::istream& in)
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_capacity_in_kg;
        cout << "Cargo: ";
        in >> m_current_load_in_kg;

        return in;
    }
    std::ostream& operator<<(std::ostream& ostr, Truck& T)
    {
        return T.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Truck& T)
    {
        return T.read(istr);
    }

}