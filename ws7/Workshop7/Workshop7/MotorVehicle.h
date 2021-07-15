/* Workshop 7 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/14
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#include <iostream>
namespace sdds
{
    class MotorVehicle
    {
         char m_license[9]{};
         char m_address[64]{};
        int m_year{};

    public:
        MotorVehicle();
        MotorVehicle(const char licensePlate[], int year);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os)const;
        std::istream& read(std::istream& in);

    };

    std::ostream& operator<<(std::ostream& ostr, const MotorVehicle&);
    std::istream& operator>>(std::istream& istr, MotorVehicle& );
}

#endif // !SDDS_MOTORVEHICLE_H

