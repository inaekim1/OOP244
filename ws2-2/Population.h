/* Workshop 2 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/05
Section : OOP244 NBB
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

    struct Population
    {
        char* postal_code;
        int population;

    };
    void sort();
    bool load(Population&);
    bool load(const char *filename);
    void display(const Population&);
    void display();
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_