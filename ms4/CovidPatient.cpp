/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
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
#include "CovidPatient.h"
#include "Patient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
       nextCovidTicket = Patient::number() + 1;
      
   }
   char CovidPatient::type()const
   {
       return 'C';
   }
   std::istream& CovidPatient::csvRead(std::istream& istr)
   {
       Patient::csvRead(istr);
       nextCovidTicket = Patient::number() + 1;
       istr.ignore(1000, '\n');

       return istr;
   }
   std::ostream& CovidPatient::write(std::ostream& ostr)const
   {
       if (fileIO())
       {
           Patient::csvWrite(ostr);

       }
       else
       {
           ostr << "COVID TEST" << endl;
           Patient::write(ostr);
           ostr << endl;

       }

       return ostr;
   }
   std::istream& CovidPatient::read(std::istream& istr)
   {
       if (fileIO())
       {
           csvRead(istr);
       }
       else
       {
           Patient::read(istr);
       }
       return istr;
   }



}