#include "AuxClass/Authentication.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QDebug>

bool Authentication::areCredentialsCorrect(QString username, QString password)
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("18.197.197.247");
    database.setPort(3306);
    database.setDatabaseName("SafeHarbour");
    database.setUserName("root");
    database.setPassword("Lamora");

    database.open();

    QSqlQuery query;
    query.prepare("SELECT HashedPassword FROM SafeHarbour.Users WHERE Username IN (?)");
    query.bindValue(0, username);
    query.exec();
    query.first();
    QString pass = query.value(0).toString();
    qDebug() << pass;
    if(pass == Authentication::getHash(password))
        return true;
    else
        return false;

}
//ToDo: Use real hashing function.
QString Authentication::getHash(QString password)
{
    return password;
}
