/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Patient.h"
#include "Ticket.h"
#include "utils.h"
using namespace std;
namespace sdds
{

    Patient::Patient(int ticket_number, bool fileIO) : m_ticket(ticket_number)
    {
       /* m_ticket = new Ticket(ticket_number); */// memory leak 182
        m_fileIO = fileIO;

    }

    Patient::~Patient()
    {
        delete[] m_patient_name;
    }

    bool Patient::fileIO()const
    {
        return m_fileIO;
    }
    void Patient::fileIO(bool fileIO)
    {
        m_fileIO = fileIO;
    }
    bool Patient::operator==(char character)const
    {
        return type() == character;
    }
    bool Patient::operator==(const Patient& P)const
    {
        return type() == P.type();
    }
    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }
    Patient::operator Time()const
    {
        return m_ticket.operator sdds::Time();
    }
    int Patient::number()const
    {
        return m_ticket.number();
    }
    std::ostream& Patient::csvWrite(std::ostream& ostr)const
    {
        ostr << type() << "," << m_patient_name << "," << m_OHIP_number << ",";
        m_ticket.csvWrite(ostr);
        return ostr;
    }
    std::istream& Patient::csvRead(std::istream& istr)
    {
        char str[100]{};
        delete[] m_patient_name;

        istr.getline(str,100,',');
        m_patient_name = new char[strlen(str)+1];
        strCpy(m_patient_name,str);
        istr >> m_OHIP_number;
        istr.ignore();
        m_ticket.csvRead(istr);
        
        return istr;
    }
    std::ostream& Patient::write(std::ostream& ostr)const
    {
        if (m_fileIO)
        {
            csvWrite(ostr);

        }
        else
        {
            char str[100]{};
            strncpy(str, m_patient_name, 25);
            ostr << m_ticket << endl;
            ostr << str;
            ostr << ", OHIP: ";
            ostr << m_OHIP_number;

        }

        return ostr;
    }
    std::istream& Patient::read(std::istream& istr)
    {
        if (m_fileIO)
        {
            csvRead(istr);
        }
        else
        {
            char str[1000]{};
   
            delete[] m_patient_name;
            cout << "Name: ";
            istr.getline(str, '\n');
            m_patient_name = new char[strLen(str) + 1];
            strCpy(m_patient_name, str );
            m_OHIP_number = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ", true);

        }
        return istr;

    }


}
