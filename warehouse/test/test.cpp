#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "../src/include/Warehouse.hpp"
#include <iostream>

// Find all tests in test*.cpp in test/
TEST_CASE("pickItems take half of first pallet", "Warehouse::pickItems") {
    Warehouse warehouse = Warehouse();
    
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet(), 
        Pallet(), 
        Pallet()
    };
    
    Employee bert = Employee("Bert", true);
    
    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    bool successful = warehouse.pickItems("Books", 10);
    
    REQUIRE(successful);

    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    

}

TEST_CASE("pickItems take all of first pallet and half of second pallet", "Warehouse::pickItems") {
    Warehouse warehouse = Warehouse();
    
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet(), 
        Pallet()
    };
    
    Employee bert = Employee("Bert", true);
    
    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    bool successful = warehouse.pickItems("Books", 40);
    
    REQUIRE(successful);

    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);

}


TEST_CASE("pickItems take all items", "Warehouse::pickItems") {
    Warehouse warehouse = Warehouse();
    
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    Employee bert = Employee("Bert", true);
    
    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    bool successful = warehouse.pickItems("Books", 100);
    
    REQUIRE(successful);

    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);

}