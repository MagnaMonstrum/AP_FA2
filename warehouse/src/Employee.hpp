#pragma once

#include <iostream>

class Employee 
{
    private:
        std::string const name;
        bool busy;
        bool forkliftCertificate;
    public:
        std::string getName();
        bool getBusy();
        void setBusy(bool busy);
        bool getForkliftCertificate();
        void setForkliftCertificate(bool forkliftCertificate);
        Employee(std::string const name, bool forkliftCertificate);
};  