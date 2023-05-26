#include "Pallet.hpp"
#include "iContainer.hpp"
#include <iostream>

std::string Pallet::getItemName() {
    return this->itemName;
};

int Pallet::getItemCount() {
    return this->itemCount;
};

int Pallet::getRemainingSpace() {
    int remainingSpace = this->itemCapacity - this->itemCount;
    return remainingSpace;
};

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    if (this->itemName != "" && this->itemCount == 0) {
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    };
    return false;
};

bool Pallet::takeOne(){
    if (itemCount > 0) {
        this->itemCount -= 1;
        return true;
    };
    return false;
};

bool Pallet::putOne(){
    if (this->itemCount)
    this->itemCount += 1;
    return true;    
};

bool Pallet::isEmpty() {
    if (this->itemCount == 0) {
        return true;
    }
    else {
        return false;
    };
}

bool Pallet::isFull() {
    if (this->itemName != "") {
        return true;
    }
    else {
        return false;
    };
}



Pallet::Pallet(std::string itemName, int itemCount,  int itemCapacity):
    itemCount(itemCount),
    itemName(itemName),
    itemCapacity(itemCapacity)
{};

Pallet::Pallet():
    itemCount(0),
    itemName(""),
    itemCapacity(0)
{};