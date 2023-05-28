#pragma once

class iContainer
{
public:
    /// @brief virtual methode om te kunnen gebruiken in Shelf en Pallet.
    virtual bool isEmpty() = 0;
    
    /// @brief virtual methode om te kunnen gebruiken in Shelf en Pallet.    
    virtual bool isFull() = 0;
};
