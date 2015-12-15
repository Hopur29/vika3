#include "relation.h"

Relation::Relation(unsigned int scientistId, std::string scientistName, unsigned int computerId, std::string computerName)
{
    this->scientistId = scientistId;
    this->scientistName = scientistName;
    this->computerId = computerId;
    this->computerName = computerName;
}

unsigned int Relation::getScientistId()
{
    return scientistId;
}

std::string Relation::getScientistName()
{
    return scientistName;
}

unsigned int Relation::getComputerId()
{
    return computerId;
}

std::string Relation::getComputerName()
{
    return computerName;
}

