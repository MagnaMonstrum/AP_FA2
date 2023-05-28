#include "..\src\include\Shelf.hpp"
#include "..\src\include\Pallet.hpp"
#include <iostream>


bool Shelf::isEmpty() {
    for (int i = 0; i < this->pallets.size(); i++) {
        if (!this->pallets[i].isEmpty()) {
            return false;
        }
    }
    return true;
};

bool Shelf::isFull() {
    for (int i = 0; i < this->pallets.size(); i++) {
        if (!this->pallets[i].isFull()) {
            return false;
        }
    }
    return true;
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