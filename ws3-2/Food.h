/* Workshop 3 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/02

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds
{
    class Food
    {
        char m_foodName[30];
        int m_calNum;
            //valid between 0 and 3000 calories (including 3000).
        int  m_timeOfConsumption;
        //values 1, 2, 3 or 4 (see Meal time and their code)

    public :
        void setName(const char* name);
        void setEmpty();
        void set(const char* name, int num, int time);
        bool isValid()const;
        int time()const;
        int calNum()const;
        void display()const;

    };
}
#endif