/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2020/7/17  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
namespace sdds
{
    class Patient :
        public IOAble
    {
        char* m_patient_name{};
        int m_OHIP_number{};
        bool m_fileIO{};
        Ticket m_ticket = 0;
     
    public :

        Patient(int ticket_number = 0, bool fileIO = false);
        Patient(const Patient&) = delete;
        Patient& operator=(const Patient&) = delete;

        virtual ~Patient() = 0;
        virtual char type()const = 0;
        bool fileIO()const;
        void fileIO(bool);
        bool operator==(char)const;
        bool operator==(const Patient&)const;
        void setArrivalTime();
        operator Time()const;
        int number()const;

        std::ostream& csvWrite(std::ostream&)const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);

    };

}
#endif

