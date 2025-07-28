#include "Item.h"
#include "Pantry.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::cin;

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

//Pantry Implementation
//Contructors
Pantry::Pantry(){}
Pantry::Pantry(std::vector<Item> items){ pantry = items; }

//Methods
void Pantry::addItem(Item& item){ pantry.push_back(item); }

void Pantry::editItem(Item& edItem, int ind){ pantry.at(ind) = edItem; }
bool Pantry::deleteItem(int ind){
    if(ind >= 0 && ind < pantry.size()){
        pantry.erase(pantry.begin() + ind);
        return true;
    }
    return false;
}
std::vector<Item> Pantry::getPantry(){ return pantry; }
//Operator Overloads
std::ostream& operator<<(std::ostream& os, const Pantry& pant){
    os << "Pantry {\n";
    for(int i = 0; i < pant.pantry.size(); i++){
        if(i != pant.pantry.size()-1){
            os << "   " << pant.pantry.at(i) << "\n";
        }
        else{
            os << "   " << pant.pantry.at(i);
        }
    }
    os << "\n}";
    return os;
}
bool operator==(const Pantry& p1, const Pantry& p2) { return p1.pantry == p2.pantry; }
int main() {
    //Item test (Phase 01)
    Item item1("Grain", "Bread", 5, "Counter");
    Item item2("Dairy", "Milk", 31, "Fridge");
    cout << "~~~PHASE 01 TEST~~~\nItems 1 and 2:\n" << item1 << "\n" << item2 << "\nEquality: " << (item1 == item2) << "\n\n";
    Item item3;
    item3.setDaysTilExp(31);
    item3.setType("Dairy");
    item3.setName("Milk");
    item3.setLoc("Fridge");
    cout << "Items 2 and 3:\n" << item2 << "\n" << item3 << "\nEquality: " << (item2 == item3);

    //Pantry Test (Phase 02)
    Pantry p1({item1, item2});
    int choice;
    cout << "\n\n~~~PHASE 02 MENU~~~\n";
    cout << "Please select from the following choices:\n";
    cout << "1) Add an item to the pantry\n";
    cout << "2) Delete an item in the pantry\n";
    cout << "3) Modify an item in the pantry\n";
    cout << "4) Show all items in the pantry\n>>";
    cin >> choice;

    if(choice == 1){
        std::string type, name, loc;
        int days;
        cout << "\nEnter item name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter item type: ";
        getline(cin, type);
        cout << "Enter days until expiration: ";
        cin >> days;
        cin.ignore();
        cout << "Enter location: ";
        getline(cin, loc);

        Item newItem(type, name, days, loc);
        p1.addItem(newItem);
        cout << "\nItem added!\n";

    }
    else if(choice == 2){
        int index;
        cout << "\nEnter index of item to delete (0-based): ";
        cin >> index;
        if(p1.deleteItem(index)){
            cout << "Item deleted successfully.\n";
        }
        else{
            cout << "Error, Invalid index\n";
        }

    }
    else if(choice == 3){
        int index;
        cout << "\nEnter index of item to modify (0-based): ";
        cin >> index;
        if(index < 0 || index >= p1.getPantry().size()){
            cout << "Error, Invalid index\n";
        }
        else{
            std::string type, name, loc;
            int days;
            cin.ignore();
            cout << "Enter new item name: ";
            getline(cin, name);
            cout << "Enter new item type: ";
            getline(cin, type);
            cout << "Enter new days until expiration: ";
            cin >> days;
            cin.ignore();
            cout << "Enter new location: ";
            getline(cin, loc);

            Item updated(type, name, days, loc);
            p1.editItem(updated, index);
            cout << "Item updated!\n";
        }

    }
    else if (choice == 4){
        cout << "\nCurrent pantry contents:\n" << p1 << "\n";
    }
    else{
        cout << "\nError, Invalid option\n";
    }
    return 0;
}