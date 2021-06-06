/* Workshop 2 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/05
Section : OOP244 NBB
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//second submission : commented codes are deleted

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

    int numOfpop = 0;
    Population* pops;

    void sort()
    {
        int i, j;
        Population temp;
        for (i = numOfpop - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (pops[j].population > pops[j + 1].population)
                {
                    temp = pops[j];
                    pops[j] = pops[j + 1];
                    pops[j + 1] = temp;
                }
            }
        }
    }


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
       

       
        if (openFile(filename))
        {
            numOfpop = noOfRecords();
            pops = new Population[numOfpop];
            int count = 0;
       
            ret = true;
            while (load(pops[count]))
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
            }
            closeFile();
        }
        else
        {
            cout << "Could not open data file : " << filename << endl;
        }
        
        return ret;
    }
    void display(const Population& pops)
    {

        cout << pops.postal_code << ":  " << pops.population <<endl;

    }
    
    void display()
    {
        int countPop = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < numOfpop; i++)
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
        for (int i = 0; i < numOfpop; i++)
        {
            delete[] pops[i].postal_code;
            pops[i].postal_code = nullptr;
        }
        delete pops;
        pops = nullptr;

    }


}