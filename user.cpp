#include "user.h"
#include <QString>

User::User(QString U, QString P) : username(U), password(P) {}

QString User::Username() {
    return username;
}

QString User::Password() {
    return password;
}
