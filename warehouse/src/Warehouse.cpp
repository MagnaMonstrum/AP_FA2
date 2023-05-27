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
        for (int i = 0; i < shelf.pallets.size()-1; i++){
            for (int i = 0; i < shelf.pallets.size()-1; i++) {
                if (shelf.pallets[i].getItemCount() > shelf.pallets[i + 1].getItemCount()) {
                    shelf.swapPallet(i, (i + 1));
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