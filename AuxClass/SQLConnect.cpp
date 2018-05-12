#include "SQLConnect.h"
#include "QSqlDatabase"

QSqlDatabase database;

void SQLConnect::ConnectToDB()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("18.197.197.247");
    database.setPort(3306);
    database.setDatabaseName("SafeHarbour");
    database.setUserName("root");
    database.setPassword("Lamora");

    database.open();
}

void SQLConnect::DisconnectDB()
{
    database.close();
    database = QSqlDatabase();
    database.removeDatabase(database.connectionName());
}

void SQLConnect::debugQuery(QSqlQuery query){
    if(!query.exec()){
        qDebug() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError().number();
    }
}
