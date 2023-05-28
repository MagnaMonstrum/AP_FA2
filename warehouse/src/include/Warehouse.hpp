#pragma once

#include "Employee.hpp"
#include "Shelf.hpp"
#include <array>


class Warehouse 
{    
    public:
        /// @brief vector om bij te houden welke employees er werken in het warehuis.
        std::vector<Employee> employeeList = {};

        /// @brief vector om bij te houden welke shelfs er zijn in het warehuis.
        std::vector<Shelf> shelves = {};

        /// @brief methode om een employee toe te voegen aan een warehuis.
        /// @param employee de employee die we willen toevoegen.
        void addEmployee(Employee employee);

        /// @brief methode om een shelf toe te voegen aan een warehuis.
        /// @param employee de shelf die we willen toevoegen.
        void addShelf(Shelf shelf);

        /// @brief methode om de pallets in een shelf te sorteren van minst aantal items naar meest aantal items.
        /// @param shelf de shelf waarvan de pallets gesorteerd moeten worden.
        /// @return true als het sorteren gelukt is.
        /// @details maakt gebruik van de swapPalles methode en simpel sorteer algoritme om de pallets te sorteren.
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(std::string itemName, int itemCount);
        std::vector<Shelf> getShelves();
        Warehouse();
};

