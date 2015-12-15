#include "linkservice.h"

#include <string>

using namespace std;

LinkService::LinkService()
{

}

bool LinkService::addLink(string scientistId, string computerId)
{
    return linkRepo.addLink(scientistId, computerId);
}

std::vector<Relation> LinkService::getAllRelation()
{
    return linkRepo.getAllRelation();
}
