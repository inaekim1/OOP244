/* Workshop 2 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/02

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != nullptr;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* employee_name)
   {
       bool ret = false;
      
       if(fscanf(fptr, "%[^\n]\n", employee_name) == 1)
       {
           ret = true;
       }
       return ret;
   }
   bool read(int& employee_number)
   {
       bool ret = false;
        
       if (fscanf(fptr, "%d,", &employee_number) == 1)
       {
           
           ret = true;
       }
           
   return ret;
   }
   bool read(double& employee_salary)
   {
       bool ret = false;

       if (fscanf(fptr, "%lf,", &employee_salary) == 1)
       {
           
           ret = true;
       }

       return ret;
   }
}