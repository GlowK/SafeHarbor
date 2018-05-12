#ifndef SQLCONNECT_H
#define SQLCONNECT_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

class SQLConnect
{
public:
    static void ConnectToDB();
    static void DisconnectDB();
    static void debugQuery(QSqlQuery);
};

#endif // SQLCONNECT_H
