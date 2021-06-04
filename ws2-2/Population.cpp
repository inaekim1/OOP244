#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

    int numOfpop = 0;
    Population* pops;

    bool load(Population& pop)
    {
        bool ok = false;
        char postal[100];
        int number = 0;

            if (read(postal) && read(number))
            {
                pop.postal_code = new char[strLen(postal) + 1];
                strCpy(pop.postal_code, postal);
                pop.population = number;
                ok = true;

            }


        return ok;
    }

    bool load(const char *filename)
    {
        bool ret = false;
       /* int count = 0;*/

        numOfpop = noOfRecords();
        pops = new Population[numOfpop];
        if (openFile(filename))
        {
            for (int i = 0; i < numOfpop; i++)
            {
                load(pops[i]);
            }
            ret = true;
           /* while (load(pops[count]))
            {
                count++;
            }
            if (count == numOfpop)
            {
                ret = true;
            }
            else
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted! " << endl;
            }*/
            closeFile();
        }
        else
        {
            cout << "Could not open data file : " << filename << endl;
        }
        /*closeFile();*/
        return ret;
    }
    void display(const Population& pops)
    {

        cout << pops.postal_code << ":" << "   " << pops.population << endl;

    }
    
    void display()
    {
        int countPop = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < 14; i++)
        {
            cout << i+1 << "- ";
            display(pops[i]);
            countPop += pops[i].population;

        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << countPop << endl;
    }



    void deallocateMemory()
    {
        for (int i = 0; i < noOfRecords(); i++)
        {
            delete[] pops[i].postal_code;
            pops[i].postal_code = nullptr;
        }
        delete pops;
        pops = nullptr;

    }


}