#include "Item.h"
#include "Pantry.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::cin;




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
    Pantry p1;
    int choice;
    while(true){
    cout << "\n\n~~~PHASE 02 MENU~~~\n";
    cout << "Please select from the following choices:\n";
    cout << "1) Add an item to the pantry\n";
    cout << "2) Delete an item in the pantry\n";
    cout << "3) Modify an item in the pantry\n";
    cout << "4) Show all items in the pantry\n";
    cout << "5) Exit\n>>";
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
    else if(choice == 5){
        cout << "You Exited the Project!";
        break;
    }
    else{
        cout << "Invalid Input!\n";
    }
    }
    return 0;
}