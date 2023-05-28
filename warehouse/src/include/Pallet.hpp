#pragma once
#include "icontainer.hpp"
#include <iostream>


class Pallet : public iContainer
{
    private:
        /// @brief int om de hoeveelheid items in een pallet te bewaren.
        mutable int itemCount;

        /// @brief string om de naam van het bewaarde item in een shelf te bewaren.
        mutable std::string itemName;

        /// @brief int om de maximum capaciteit van de pallet te bewaren.
        mutable int itemCapacity;

    public:
        /// @brief methode om de naam van de item waarmee pallet gevuld is te returnen.
        /// @return naam van de item waar de pallet mee gevuld is.
        std::string getItemName();

        /// @brief methode om de de hoeveelheid items op de pallet te returnen.
        /// @return een int die gelijkstaat aan de hoeveelheid items op de pallet.
        int getItemCount();

        /// @brief methode om de hoeveelheid vrije plekken te returnen.
        /// @return int die gelijkstaat aan de capaciteit van de pallet min de hoeveel items op de pallet. het aantal vrije plekken dus.
        int getRemainingSpace();

        /// @brief methode om te checken of een pallet leeg is, als deze leeg is geven we een nieuwe item aan de pallet met een nieuwe capaciteit.
        /// @param itemName string om een nieuwe itemName te zetten.
        /// @param itemCapacity int om een nieuwe capaciteit te zetten.
        /// @return true als het gelukt is om een nieuwe item op de pallet te leggen, false als dit niet gelukt is.
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);

        /// @brief methode om 1 item van de hoeveelheid items op de pallet af te halen.
        /// @return true als het gelukt om 1 item van de pallet af te halen (als er meer dan 0 items op de pallet liggen).
        bool takeOne();

        /// @brief methode om 1 item toetevoegen aan de hoeveelheid items op de pallet.
        /// @return true als het gelukt om 1 item toetevoegen aan de pallet. false als dat niet gelukt is.
        bool putOne();

        /// @brief methode om te checken of een pallet leeg is.
        /// @return true als de itemCount van de pallet leeg is. false als dat niet zo is
        bool isEmpty();

        /// @brief methode om te checken of een pallet vol is.
        /// @return true als de capaciteit an de pallet gelijk staat aan de hoeveelheid items op de pallet.
        bool isFull();

        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();
};