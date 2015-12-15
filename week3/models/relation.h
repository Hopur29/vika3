#ifndef RELATION_H
#define RELATION_H

#include <string>


class Relation
{
public:
    Relation(unsigned int scientistId, std::string scientistName, unsigned int computerId, std::string computerName);

    unsigned int getScientistId();
    std::string getScientistName();
    unsigned int getComputerId();
    std::string getComputerName();

private:
    unsigned int scientistId;
    std::string scientistName;
    unsigned int computerId;
    std::string computerName;
};

#endif // RELATION_H
