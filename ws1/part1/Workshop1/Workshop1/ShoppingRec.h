/*
    Workshop 1 part 1
    Name : Inae Kim
    Seneca email : ikim36@myseneca.ca
    Seneca ID : 132329202
    Section : OOP244 NBB
*/

#pragma once
#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H

namespace sdds
{
    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;

    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}





#endif