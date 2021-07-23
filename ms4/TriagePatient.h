/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/22  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"
namespace sdds {

    class TriagePatient : public Patient
    {
        char* m_symptoms;

    public:
        TriagePatient();
        char type()const;
        ~TriagePatient();
        std::ostream& csvWrite(std::ostream&)const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
}
#endif // !SDDS_TRIAGEPATIENT_H


