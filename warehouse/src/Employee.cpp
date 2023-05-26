#include "Employee.hpp"
#include  <iostream>


std::string Employee::getName() {
    /// @brief
    /// returned de naam van een employee.  
    return this->name;
};

/// @brief
/// returned de naam een boolean die aangeeft of een employee bezig is. 
bool Employee::getBusy() {
    return this->busy;
};

/// @brief
/// veranderd de busy status van een employee naar true of false.
/// @param busy de busy status van een employee wordt gelijk gezet aan deze busy parameter van de methode. 
void Employee::setBusy(bool busy) {
    this->busy = busy;
};

/// @brief
/// returned de forkliftCertificate statuts van de employee.
bool Employee::getForkliftCertificate() {
    return this->forkliftCertificate;
};

/// @brief
/// veranderd de setForkliftCertificate status van een employee naar true of false.
/// @param forkliftCertificate de forkliftCertificate status van een employee wordt gelijk gezet aan deze forkliftCertificate parameter van de methode. 
void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
};
/// @brief
/// dit is de constructor van de employee klasse, hiermee kunnen nieuwe employees aangemaakt worden.
/// @param name hiermee wordt de naam van de employee bepaald.
/// @param forkliftCertificate hiermee wordt de forkliftCertificate status van de employee bepaald.
Employee::Employee(std::string const name, bool forkliftCertificate):
    name(name),
    forkliftCertificate(forkliftCertificate)  
{};
