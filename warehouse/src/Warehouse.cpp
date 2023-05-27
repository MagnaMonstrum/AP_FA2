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
                    for(int l = shelves[i].pallets[j].getItemCount(); l < shelves[i].pallets[j].getItemCount(); l--) {
                        shelves[i].pallets[j].takeOne();
                        itemCount--;
                    };
                };
            }
        }

        return true;
    };
    return false;
};
 
 
bool Warehouse::rearrangeShelf(Shelf& givenShelf) {
    
    bool availableEmployee = false;

    for (Employee employee : this->employeeList) {
        if (employee.getForkliftCertificate() == true && employee.getBusy() == false) {
            availableEmployee = true;            
        }
    }
    if (!availableEmployee) {
        return false;
    }
    else {
        for (int i = 0; i < givenShelf.pallets.size()-1; i++) {

            for (int j = 0; j < givenShelf.pallets.size()-1; j++) {
                
                if (givenShelf.pallets[j].getItemCount() > givenShelf.pallets[j + 1].getItemCount()) {
                    givenShelf.swapPallet(j, (j + 1));
                }
            }
        }
        return true;
    }
}

std::vector<Shelf> Warehouse::getShelves() {
    return this->shelves;
}
Warehouse::Warehouse() {}