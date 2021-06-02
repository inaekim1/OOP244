/*
    Workshop 1 part 1
    Name : Inae Kim
    Seneca email : ikim36@myseneca.ca
    Seneca ID : 132329202
    Section : OOP244 NBB
*/


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "ShoppingRec.h"
namespace sdds
{
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);

}





#endif // !SDDS_FILE_H