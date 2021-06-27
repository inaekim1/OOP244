/* Workshop 5 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/27
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
     operator int()const;
     operator double()const;
     bool operator~()const;
    Account& operator=(Account&);
    Account& operator=(int value);
    Account& operator+=(double value);
    Account& operator-=(double value);
    Account& operator<<(Account&);
    Account& operator>>(Account&);

   };
   
   double operator+(const Account& left, const Account& right);
   double& operator+=(double& left, const Account& right);

}
#endif // SDDS_ACCOUNT_H_