#include "Item.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

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


int main() {
    Item item1;
    Item item2("Dairy", "Milk", 31, "Fridge");
    cout << "Items 1 and 2:\n" << item1 << "\n" << item2 << "\nEquality: " << (item1 == item2) << "\n\n";
    Item item3;
    item3.setDaysTilExp(31);
    item3.setType("Dairy");
    item3.setName("Milk");
    item3.setLoc("Fridge");
    cout << "Items 2 and 3:\n" << item2 << "\n" << item3 << "\nEquality: " << (item2 == item3);
    return 0;
}