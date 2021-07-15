/* Workshop 7 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/14
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"
namespace sdds
{
    class Truck : public MotorVehicle
    {
        double m_capacity_in_kg{};
        double m_current_load_in_kg{};

    public:
        Truck(const char licensePlate[], int year, double capacity, const char address[]);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os);
        std::istream& read(std::istream& in);

    };

    std::ostream& operator<<(std::ostream& ostr, Truck&); // add const if able
    std::istream& operator>>(std::istream& istr, Truck&);
}


#endif // SDDS_TRUCK_H

