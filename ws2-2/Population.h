
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

    struct Population
    {
        char* postal_code;
        int population;

    };
    bool load(Population&);
    bool load(const char *filename);
    void display(const Population& pops);
    void display();
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_