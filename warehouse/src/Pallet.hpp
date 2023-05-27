#pragma once
#include "icontainer.hpp"
#include <iostream>


class Pallet : public iContainer
{
    private:
        mutable int itemCount;
        mutable std::string itemName;
        mutable int itemCapacity;

    public:
        std::string getItemName();
        int getItemCount();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();
        bool isEmpty();
        bool isFull();
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();
};