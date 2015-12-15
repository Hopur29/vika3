#include "computer.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

using namespace std;

Computer::Computer()
{

}

Computer::Computer(string name, enum computerType type)
{
    id = 0;
    this->name = name;
    this->type = type;
    this->yearBuilt = constants::YEAR_UNSELECTED_VALUE2;
}

Computer::Computer(string name, enum computerType type, int yearBuilt)
{
    id = 0;
    this->name = name;
    this->type = type;
    this->yearBuilt = yearBuilt;
}

Computer::Computer(unsigned int id, std::string name, enum computerType type, int yearBuilt)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->yearBuilt = yearBuilt;
}

unsigned int Computer::getId()
{
    return id;
}

string Computer::getName()
{
    return name;
}

int Computer::getYearBuilt()
{
    return yearBuilt;
}

enum computerType Computer::getType()
{
    return type;
}

string Computer::getTypeName()
{
    if (type == electronic)
    {
        return "Electronic";
    }
    else if (type == mechatronic)
    {
        return "Mechatronic";
    }
    else if (type == transistor)
    {
        return "Transistor";
    }
    else
    {
        return "Other";
    }
}

bool Computer::wasBuilt()
{
    return yearBuilt != constants::YEAR_UNSELECTED_VALUE2;
}

std::vector<Scientist> Computer::getScientists()
{
    return scientists;
}

void Computer::setScientists(std::vector<Scientist> newScientists)
{
    scientists = newScientists;
}
bool Computer::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "electronic" && type == electronic)
    {
        return true;
    }

    if (searchTermLower == "mechatronic" && type == mechatronic)
    {
        return true;
    }
    if (searchTermLower == "transistor" && type == transistor)
    {
        return true;
    }
    if (searchTermLower == "other" && type == other)
    {
        return true;
    }

    string yearBuiltString = utils::intToString(yearBuilt);

    if (yearBuiltString.find(searchTerm) != string::npos)
    {
        return true;
    }

    if (yearBuilt != constants::YEAR_UNSELECTED_VALUE2)
    {
        string yearBuiltString = utils::intToString(yearBuilt);

        if (yearBuiltString.find(searchTerm) != string::npos)
        {
            return true;
        }
    }
    else
    {
        if (searchTermLower == "Not Built")
        {
            return true;
        }
    }

    return false;
}
