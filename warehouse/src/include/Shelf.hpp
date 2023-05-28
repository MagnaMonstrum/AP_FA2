#pragma once

#include <iostream>
#include <vector>
#include "Pallet.hpp"
#include <array>
#include "iContainer.hpp"

class Shelf : public iContainer
{
    public:
        /// @brief array om de pallets in de shelf te bewaren.
        std::array<Pallet, 4> pallets;

        /// @brief methode die de status van de pallets in de shelf returned, of deze vol zijn of niet.
        /// @return een array van booleans, ieder boolean is true als deze vol is en false als dat niet zo is.
        std::array<bool, 4> getSlotStatus();

        /// @brief methode om pallets op 2 verschillende indexen van plaats te wisselen.
        /// @param index0 int om de index van de eerste pallet de we willen hebben te bewaren.
        /// @param index1 int om de index van de tweede pallet de we willen hebben te bewaren.
        /// @return true als het gelukt om de pallets om te wisselen van plek.
        bool swapPallet(int index0, int index1); 

        /// @brief deze methode maakt gebruik van een loop om te checken of iedere pallet te checken of iedere pallet leeg is. als iedere pallet leeg is dan is de shelf ook leeg.
        /// @return true als de shelf leeg is, false als dat niet zo is.
        bool isEmpty();

        /// @brief deze methode maakt gebruik van een loop om te checken of iedere pallet te checken of iedere pallet vol is. als iedere pallet vol is dan is de shelf ook vol.
        /// @return true als de shelf vol is, false als dat niet zo is.
        bool isFull();

        Shelf();
};
