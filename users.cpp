#include "users.h"
#include<QDebug>
using namespace std;

Users::Users() {
    registeredUsers["roaa"] = 4;

}

void Users::addUser(QString n, int pass) {
    registeredUsers[n] = pass;

}

void Users::removeUser(QString n) {
    registeredUsers.erase(n);
}

bool Users::findUser(QString n, int p) {
    auto it = registeredUsers.find(n);
    if (it != registeredUsers.end() && it->second== p) {
        return true;
    }
    else {
        return false;
    }
}

void Users::editUser(QString oldName, QString editedName, int editedValue) {
    registeredUsers.erase(oldName);
    registeredUsers.insert({ editedName, editedValue });
}

void Users::editUserName(QString oldName, QString editedName) {
    registeredUsers.insert({ editedName, registeredUsers[oldName] });
    registeredUsers.erase(oldName);
}

void Users::editUserPassword(QString name, int editedValue) {
    registeredUsers[name] = editedValue;
}
