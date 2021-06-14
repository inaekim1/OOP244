/* Workshop 3 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/14
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds
{
    class CalorieList
    {
        Food* foods;
        char m_title[37];
        int m_noOfFood;
        int m_foodAdded;
        int totalCalorie()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;

    public:  

       
        // sets the CalorieList to accept the "size" number of Food Items. 
// This function is called to prepare the CalorieList for accepting food items
        void init(int size);
        // Adds Food Items using their Name, Calorie count and time of consumption up to 
        // the number set in the init() function, returns true if successful.
        bool add(const char* item_name, int calories, int when);
        // Displays the report with food information and the total calorie consumed in the day
        // as shown in the report sample
        void display()const;
        // Releases all the memory used. After this function init() can be called for another
        // report;
        void deallocate();

    };
  

}

#endif

