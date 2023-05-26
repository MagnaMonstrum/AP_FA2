#pragma once

#include "Employee.hpp"
#include "Shelf.hpp"
#include <array>


class Warehouse 
{    
    public:
        std::vector<Employee> employeeList = {};
        // De grootte van de Shelf array moet gelijk zijn aan het aantal shelves dat gebruikt wordt, anders werkt pickItems niet.
        std::vector<Shelf> shelves = {};
        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(std::string itemName, int itemCount);
        std::vector<Shelf> getShelves();
        Warehouse();
};

