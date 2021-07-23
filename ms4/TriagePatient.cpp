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
#include <iostream>
#include "TriagePatient.h"
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient()  : Patient(nextTriageTicket)
   {
       m_symptoms = nullptr;
       nextTriageTicket = Patient::number() + 1;
   }
   char TriagePatient::type()const
   {
       return 'T';
   }
   TriagePatient::~TriagePatient()
   {
       delete[] m_symptoms;
   }
   std::ostream& TriagePatient::csvWrite(std::ostream&  ostr)const
   {
       
       Patient::csvWrite(ostr);
       ostr << "," << m_symptoms;

       return ostr;

   }
   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
       delete[] m_symptoms;
       m_symptoms = nullptr;
       Patient::csvRead(istr);
       istr.ignore();
       m_symptoms = getcstr(NULL, istr, '\n');
       nextTriageTicket = Patient::number() + 1;



       return istr;

   }
   std::ostream& TriagePatient::write(std::ostream& ostr)const
   {
       if (fileIO())
       {
           csvWrite(ostr);
       }
       else
       {
           ostr << "TRIAGE" << endl;
           Patient::write(ostr);
           ostr << endl;
           ostr << "Symptoms: " << m_symptoms << endl;

       }

       return ostr;
   }
   std::istream& TriagePatient::read(std::istream& istr)
   {
       if (fileIO())
       {
           csvRead(istr);

       }
       else
       {
           delete[] m_symptoms;
           m_symptoms = nullptr;
           Patient::read(istr);
           m_symptoms = getcstr("Symptoms: ", istr, '\n');

          
       }
 

       return istr;

   }
}