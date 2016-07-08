#ifndef USER_H
#define USER_H

#include <QString>
class User
{
private:
    QString username;
    QString password;
protected:
    User(QString="Mario", QString="Rossi");
public:
    QString Username();
    QString Password();
};

#endif // USER_H
