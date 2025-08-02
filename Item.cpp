#include "Item.h"

//Item Implementation
//Constructors
Item::Item() : type(""), name(""), daysTilExp(0), loc(""){}
Item::Item(std::string t, std::string n, int d, std::string l) : type(t), name(n), daysTilExp(d), loc(l){}

//Getters
std::string Item::getType() const { return type; }
std::string Item::getName() const { return name; }
int Item::getDaysTilExp() const { return daysTilExp; }
std::string Item::getLoc() const{ return loc; }
//Setters
void Item::setType(const std::string& t) { type = t; }
void Item::setName(const std::string& n) { name = n; }
void Item::setDaysTilExp(int d) { daysTilExp = d; }
void Item::setLoc(const std::string& l) { loc = l; }
//Operator Overloads
std::ostream& operator<<(std::ostream& os, const Item& item){
    os << "Item [Name: " << item.name << ", Type: " << item.type << ", Days Until Expiration: " << item.daysTilExp << ", Location: " << item.loc << "]";
    return os;
}
bool operator==(const Item& item1, const Item& item2){
    return item1.name == item2.name &&
           item1.type == item2.type &&
           item1.daysTilExp == item2.daysTilExp &&
           item1.loc == item2.loc;
}