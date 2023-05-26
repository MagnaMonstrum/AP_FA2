#include "Warehouse.hpp"
#include "Employee.hpp"
#include "Shelf.hpp"
#include <bits/stdc++.h> 

void Warehouse::addEmployee(Employee employee) {
    this->employeeList.push_back(employee);
};

void Warehouse::addShelf(Shelf shelf) {
    this->shelves.push_back(shelf);
};

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int targetCount = 0;
    for (int i = 0; i < shelves.size(); i++) {
        for (int j = 0; j < shelves[i].pallets.size(); j++) {
            if (shelves[i].pallets[j].getItemName() == itemName) {
                targetCount += shelves[i].pallets[j].getItemCount();
            }
        };
    };

    if (targetCount >= itemCount) {
        for (int i = 0; i < shelves.size(); i++) {

            for (int j = 0; j < itemCount; j++) {
                if (shelves[i].pallets[j].getItemCount() < itemCount && shelves[i].pallets[j].getItemName() == itemName) {
                    for(int l; l < shelves[i].pallets[j].getItemCount(); l--) {
                        shelves[i].pallets[j].takeOne();
                    };
                };
            }
        }

        return true;
    };
    return false;
};
 
 
bool Warehouse::rearrangeShelf(Shelf& shelf) {
    
    std::vector<int> palletValues = {};
    std::array<Pallet, 100> newPallets = {};

    int min;
    
    for (int i = 0; i < shelf.pallets.size(); i++) {

        int itemsTotal = 0;

        for (int j = 0; j < shelf.pallets.size(); j++) {
            itemsTotal += shelf.pallets[j].getItemCount();                 
        }

        palletValues.push_back(itemsTotal);
    }
    
    min = *std::min_element(palletValues.begin(), palletValues.end());

    for (int i = 0; i < palletValues.size(); i++) {
        
        if (palletValues[i] == min && palletValues[i] > -1) {
            min = *std::min_element(palletValues.begin(), palletValues.end());
            newPallets[newPallets.size()] = shelf.pallets[i];
            palletValues.erase(palletValues.begin()+i);
            palletValues[i] = -1;
        }

    }

    for (int i = 0; i < shelf.pallets.size(); i++) {
        shelf.pallets[i] = newPallets[i];
        std::cout << &newPallets[i];
    }

    return true;
}

std::vector<Shelf> Warehouse::getShelves() {
    return this->shelves;
}
Warehouse::Warehouse() {}