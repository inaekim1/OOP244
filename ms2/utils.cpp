/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.cpp
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2020/7/4  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   int getInt(const char* prompt)
   {
       if (prompt != nullptr)
       {
           cout << prompt;
       }
       int value = 0;
       char ch{};
       cin >> value;
       cin.get(ch);
       while (cin.fail() || ch != '\n')
       {
           if (cin.fail())
           {
               cout << "Bad integer value, try again: ";
           }
           else if (ch != '\n')
           {
               cout << "Enter only an integer, try again: ";
           }
           cin.clear();
           cin.ignore(1000, '\n');
           cin >> value;
           cin.get(ch);
       }
       cin.clear();
       return value;

       }
   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       if (prompt != nullptr)
       {
           cout << prompt;
       }
       int value = 0;
       char ch{};
       cin >> value;
       cin.get(ch);
       while (cin.fail() || ch != '\n' || value < min || value > max)
       {
           if (cin.fail())
           {
               cout << "Bad integer value, try again: ";
               cin.clear();
               cin.ignore(1000, '\n');
           }
           else if (ch != '\n')
           {
               cout << "Enter only an integer, try again: ";
               cin.clear();
               cin.ignore(1000, '\n');
           }
           else if (value < min || value > max)
           {
               if (errorMessage != nullptr)
               {
                   cout << errorMessage;
               }
               if (showRangeAtError)
               {
                   cout << "[" << min << " <= value <= " << max << "]: ";
               }
           }
         
         /*  cin.ignore(1000, '\n');*/
           cin.clear();
           cin >> value;
           cin.get(ch);
       }
       cin.clear();
      
       return value;
   }
   char* getcstr(
       const char* prompt,   // User entry prompt
       std::istream& istr,  // the Stream to read from
       char delimiter   // Delimiter to mark the end of data
   )
   {
       if (prompt != nullptr)
       {
           cout << prompt;
       }
       char str[1800]{};
       char* str2 = nullptr;
      istr.getline(str, 1000, delimiter);
       str2 = new char[strlen(str) + 1];
       strcpy(str2, str);
       
       return str2;
   }

     
   }
   