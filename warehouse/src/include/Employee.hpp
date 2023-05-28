#pragma once

#include <iostream>

class Employee 
{
    private:
        std::string const name;
        bool busy;
        bool forkliftCertificate;
    public:
        /// @brief
        /// Geeft naam van employee.
        /// @return De naam van de employee.  
        std::string getName();

        /// @return de naam van een employee
        bool getBusy();

        void setBusy(bool busy);
        bool getForkliftCertificate();
        void setForkliftCertificate(bool forkliftCertificate);
        Employee(std::string const name, bool forkliftCertificate);
};  