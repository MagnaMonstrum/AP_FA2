#include <iostream>

#include "src\Warehouse.hpp"

int main(void){
    std::cout << "Hello world" << std::endl;
    
    Warehouse warehouse = Warehouse();
        Shelf shelf1 = Shelf();
        shelf1.pallets = {
            Pallet("Books", 100, 40), 
            Pallet("Boxes", 100, 10), 
            Pallet("Books", 100, 20), 
            Pallet("Books", 100, 20)
        };

        Shelf shelf2 = Shelf();
        shelf2.pallets = {
            Pallet("Books", 100, 15), 
            Pallet("Boxes", 100, 20), 
            Pallet("Books", 100, 5), 
            Pallet("Boxes", 100, 30)
        };

        Shelf shelf3 = Shelf();
        shelf3.pallets = {
            Pallet("Toy Bears", 100, 20), 
            Pallet("Toy Bears", 100, 10), 
            Pallet(), 
            Pallet("Toy Bears", 100, 30)
        };
        
        warehouse.addShelf(shelf1);
        warehouse.addShelf(shelf2);
        warehouse.addShelf(shelf3); 
        warehouse.pickItems("Books", 68);
        std::cout << warehouse.shelves[0].pallets[0].getItemName() << ", " << warehouse.shelves[0].pallets[0].getItemCount() << "\n";
        std::cout << warehouse.shelves[0].pallets[2].getItemName() << ", " << warehouse.shelves[0].pallets[2].getItemCount() << "\n";
        std::cout << warehouse.shelves[0].pallets[3].getItemName() << ", " << warehouse.shelves[0].pallets[3].getItemCount() << "\n";
}
