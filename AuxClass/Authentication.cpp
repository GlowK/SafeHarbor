#include "Authentication.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QDebug>
#include "SQLConnect.h"

int Authentication::checkCredentials(QString username, QString password)
{    
    SQLConnect::ConnectToDB();
    QSqlQuery query;

    query.prepare("SELECT HashedPassword FROM SafeHarbour.Users WHERE Username IN (?)");
    query.bindValue(0, username);
    query.exec();
    query.first();
    QString pass = query.value(0).toString();

    if(pass != Authentication::getHash(password) || pass == "")
    {
        SQLConnect::DisconnectDB();
        return INCORRECT_CREDENTAILS;
    }

    query.prepare("SELECT isActive FROM SafeHarbour.Users WHERE Username IN (?)");
    query.bindValue(0, username);
    query.exec();
    query.first();
    bool isActive = query.value(0).toBool();

    if(!isActive)
    {
        SQLConnect::DisconnectDB();
        return ACCOUNT_INACTIVE;
    }

    query.prepare("SELECT AccountType FROM SafeHarbour.Users WHERE Username IN (?)");
    query.bindValue(0, username);
    query.exec();
    query.first();
    QString accountType = query.value(0).toString();
    qDebug() << accountType;

    if(accountType == "Admin")
    {
        SQLConnect::DisconnectDB();
        return VALID_ADMIN;
    }
    if(accountType == "Client")
    {
        SQLConnect::DisconnectDB();
        return VALID_CLIENT;
    }
    if(accountType == "Manager")
    {
        SQLConnect::DisconnectDB();
        return VALID_MANGER;
    }
    SQLConnect::DisconnectDB();
}

//ToDo: Use real hashing function.
QString Authentication::getHash(QString password)
{
    return password;
}
