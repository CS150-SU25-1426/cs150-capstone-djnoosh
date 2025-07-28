#ifndef PANTRY_H
#define PANTRY_H
#include <iostream>
#include <vector>
#include "Item.h"

class Pantry{
    private:
        std::vector<Item> pantry;
    public:
        //Contructors
        Pantry();
        Pantry(std::vector<Item> items);

        //Methods
        void addItem(Item& item);
        void editItem(Item& edItem, int ind);
        bool deleteItem(int ind);
        std::vector<Item> getPantry();

        //Operator Overloads
        friend std::ostream& operator<<(std::ostream& os, const Pantry& pant);
        friend bool operator==(const Pantry& p1, const Pantry& p2);
};

#endif // PANTRY_H