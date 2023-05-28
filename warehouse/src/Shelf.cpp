#include "..\src\include\Shelf.hpp"
#include "..\src\include\Pallet.hpp"
#include <iostream>

std::array<bool, 4> Shelf::getSlotStatus() {
    return this->palletStatus;
}

bool Shelf::isEmpty() {

    std::array<bool, 4> y = {false, false, false, false};

    if (this->getSlotStatus() == y) {
        return true;
    }
    else {
        return false;
    };
};

bool Shelf::isFull() {
    std::array<bool, 4> y = {true, true, true, true};

    if (this->getSlotStatus() == y) {
        return true;
    }
    else {
        return false;
    };
};

bool Shelf::swapPallet(int index0, int index1){
    Pallet temp = this->pallets[index0];
    this->pallets[index0] = this->pallets[index1];
    this->pallets[index1] = temp;
    return true;
};

Shelf::Shelf() {
    Shelf::pallets = {};
}