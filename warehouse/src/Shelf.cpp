#include "Shelf.hpp"
#include "Pallet.hpp"
#include <iostream>

std::array<bool, 4> Shelf::getSlotStatus() {
    return this->palletStatus;
}

bool Shelf::isEmpty() {
    /// @brief 
    /// deze functie maakt gebruik van de getslotStatus methode om te checken of alle plekken in een shelf leeg zijn. Dit wordt gedaan door te kijken naar een andere lijst die altijd leeg is (y) en deze te vergelijken met de huidige status.
    /// @return als de lijst leeg is dan wordt true gereturned zo niet dan wordt false gereturned.
    std::array<bool, 4> y = {false, false, false, false};

    if (this->getSlotStatus() == y) {
        return true;
    }
    else {
        return false;
    };
};

bool Shelf::isFull() {
    /// @brief 
    /// deze functie maakt gebruik van de getslotStatus methode om te checken of alle plekken in een shelf leeg zijn. Dit wordt gedaan door te kijken naar een andere lijst die altijd vol is (y) en deze te vergelijken met de huidige status.
    /// @return als de lijst vol is dan wordt true gereturned zo niet dan wordt false gereturned.
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