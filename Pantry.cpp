#include "Pantry.h"

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