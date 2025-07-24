#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item{
    private:
        std::string type; //e.g. dairy, spice, produce, etc.
        std::string name;
        int daysTilExp;
        std::string loc; // e.g. fridge, freezer, pantry (not the whole pantry), cabinet, etc.
    public:
        //Constructors
        Item();
        Item(std::string t, std::string n, int d, std::string l);

        //Getters
        std::string getType() const;
        std::string getName() const;
        int getDaysTilExp() const;
        std::string getLoc() const;

        //Setters
        void setType(const std::string& t);
        void setName(const std::string& n);
        void setDaysTilExp(int d);
        void setLoc(const std::string& l);

        //Operator Overloads
        friend std::ostream& operator<<(std::ostream& os, const Item& item);
        friend bool operator==(const Item& item1, const Item& item2);
};

#endif // ITEM_H