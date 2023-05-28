#pragma once

#include <iostream>

class Employee 
{
    private:
        std::string const name;
        bool busy;
        bool forkliftCertificate;

    public:
        /// @return De naam van de employee.  
        std::string getName();

        /// @return de busy status van de employee
        bool getBusy();

        /// @brief  zet de status van de employee naar true of false
        /// @param busy boolean om de busy status bij te houden
        void setBusy(bool busy);

        /// @brief functie om te kijken of de employee een heftruckcertificaat heeft. 
        /// @return true als de employee een heftruckcertificaat heeft, false als de employee deze niet heeft.
        bool getForkliftCertificate();

        /// @brief zet de heftruckcertificaat status van de employee naar true of false.
        /// @param forkliftCertificate is true als de employee een heftruckcertificaat heeft en false als de employee deze niet heeft.
        void setForkliftCertificate(bool forkliftCertificate);

        
        Employee(std::string const name, bool forkliftCertificate);
};  