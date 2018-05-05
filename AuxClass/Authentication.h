#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <QString>

class Authentication
{
private:
    static QString getHash(QString password);
public:
    enum AuthenticationResults
    {
        VALID_ADMIN,
        VALID_CLIENT,
        VALID_MANGER,
        INCORRECT_CREDENTAILS,
        ACCOUNT_INACTIVE
    };
    static int checkCredentials(QString username, QString password);
};

#endif // AUTHENTICATION_H
