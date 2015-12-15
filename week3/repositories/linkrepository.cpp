#include "linkrepository.h"
#include "utilities/utils.h"

#include <cstdlib>
#include <sstream>
#include <QString>

using namespace std;

LinkRepository::LinkRepository()
{
    db = utils::getDatabaseConnection();
}

bool LinkRepository::addLink(string scientistId, string computerId)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO ScientistComputerConnections (scientistId, computerId) VALUES ("
             << "'" << scientistId << "', "
             << "'" << computerId << "'"
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

std::vector<Relation> LinkRepository::getAllRelation()
{
    stringstream sqlQuery;
    sqlQuery << "SELECT scientistId, s.name sname, computerId, c.name cname from Computers c, Scientists s, ScientistComputerConnections r where r.scientistId = s.id and r.computerId = c.id" ;

    return queryRelations(QString::fromStdString(sqlQuery.str()));


}

std::vector<Relation> LinkRepository::queryRelations(QString sqlQuery)
{
    vector<Relation> relations;

    db.open();

    if(!db.isOpen())
    {
        return relations;
    }

    QSqlQuery query(db);

    if(!query.exec(sqlQuery))
    {
        return relations;
    }

    while(query.next())
    {
        int sId = query.value("scientistId").toUInt();
        string sName = query.value("sname").toString().toStdString();
        int cId = query.value("computerId").toUInt();
        string cName = query.value("cname").toString().toStdString();

        relations.push_back(Relation(sId,sName,cId,cName));
    }

    db.close();

    /*for(unsigned int = 0; i < relations.size(); i++)
    {
        Relation currentRelation = relations.at(i);

    }*/

    return relations;


}



