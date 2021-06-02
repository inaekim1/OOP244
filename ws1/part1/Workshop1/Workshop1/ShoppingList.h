/*
    Workshop 1 part 1
    Name : Inae Kim
    Seneca email : ikim36@myseneca.ca
    Seneca ID : 132329202
    Section : OOP244 NBB
*/

#pragma once
#ifndef  SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds
{
    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();

}





#endif