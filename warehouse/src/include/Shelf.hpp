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
        std::array<bool, 4> palletStatus = {};

        /// @brief methode die de status van de pallets in de shelf returned, of deze vol zijn of niet.
        /// @return een array van booleans, ieder boolean is true als deze vol is en false als dat niet zo is.
        std::array<bool, 4> getSlotStatus();

        /// @brief methode om pallets op 2 verschillende indexen van plaats te wisselen.
        /// @param index0 int om de index van de eerste pallet de we willen hebben te bewaren.
        /// @param index1 int om de index van de tweede pallet de we willen hebben te bewaren.
        /// @return true als het gelukt om de pallets om te wisselen van plek.
        bool swapPallet(int index0, int index1); 

        /// @brief deze methode maakt gebruik van de getslotStatus methode om te checken of alle plekken in een shelf leeg zijn. Dit wordt gedaan door te kijken naar een andere lijst die altijd leeg is (y) en deze te vergelijken met de huidige status.
        /// @return als de lijst leeg is dan wordt true gereturned zo niet dan wordt false gereturned.
        bool isEmpty();

        /// @brief deze methode maakt gebruik van de getslotStatus methode om te checken of alle plekken in een shelf leeg zijn. Dit wordt gedaan door te kijken naar een andere lijst die altijd vol is (y) en deze te vergelijken met de huidige status.
        /// @return als de lijst vol is dan wordt true gereturned zo niet dan wordt false gereturned.
        bool isFull();

        Shelf();
};
