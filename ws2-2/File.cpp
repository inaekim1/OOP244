#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
    FILE* fptr;


    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords()
    {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1)
        {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile()
    {
        if (fptr) fclose(fptr);
    }
    bool read(char* postal_code)
    {
        bool ret = false;

        if (fscanf(fptr, "%[^ ,],", postal_code) == 1)
        {
            ret = true;
        }
        return ret;
    }
    bool read(int& population)
    {
        bool ret = false;
        /*char ch = '\n';*/
        if (fscanf(fptr, "%d\n", &population ) == 1)
        {
            ret = true;
        }

        return ret;
    }
}
 
