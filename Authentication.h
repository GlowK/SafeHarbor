#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <QString>

class Authentication
{
private:
    static QString getHash(QString password);
public:
    static bool areCredentialsCorrect(QString username, QString password);
};

#endif // AUTHENTICATION_H
