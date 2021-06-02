/*
    Workshop 1 part 1
    Name : Inae Kim
    Seneca email : ikim36@myseneca.ca
    Seneca ID : 132329202
    Section : OOP244 NBB
*/



#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_UTILS_H // replace with relevant names
#define SDDS_UTILS_H
namespace sdds
{
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);

}


#endif
