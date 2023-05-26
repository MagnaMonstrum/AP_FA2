#pragma once

#include <iostream>
#include <vector>
#include "Pallet.hpp"
#include <array>
#include "iContainer.hpp"

class Shelf : public iContainer
{
    public:
        std::array<Pallet, 4> pallets;
        std::array<bool, 4> palletStatus = {}; // Make this the new way of checking status
        std::array<bool, 4> getSlotStatus();
        bool swapPallet(int index0, int index1);  
        bool isEmpty();
        bool isFull();
        //std::array<Pallet, 4> getPallet();
        Shelf();
};
