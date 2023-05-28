#include <iostream>

#include "src\include\Warehouse.hpp"

int main(void) { 
    
    Warehouse warehouse = Warehouse(); 
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 3), 
        Pallet("Controllers", 100, 2), 
        Pallet("Shoes", 50, 10), 
        Pallet("Shoes", 50, 1)
    };
    


    Shelf emptyShelf = Shelf();
    emptyShelf.pallets = {
        Pallet("Books", 100, 0), 
        Pallet("Controllers", 100, 0), 
        Pallet("Shoes", 50, 0), 
        Pallet("Shoes", 50, 0)
    };

    Employee bert = Employee("Bert", true);
    
    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);
    warehouse.addShelf(emptyShelf);

    warehouse.employeeList[0].setBusy(false);

    warehouse.rearrangeShelf(warehouse.shelves[0]);


    // gewenste output is:
    // Shoes
    // Controllers
    // Books
    // Shoes
    for (int i = 0; i < 4; i++) {
        std::cout << warehouse.shelves[0].pallets[i].getItemName() << std::endl;
    }

    // gewenste output is:
    // false
    std::cout << warehouse.shelves[0].isFull() << std::endl;

    // gewenste output is:
    // false
    std::cout << warehouse.shelves[1].isFull() << std::endl;  

    // gewenste output is:
    // true
    std::cout << warehouse.shelves[1].isEmpty() << std::endl;      

}
