#ifndef USERS_H
#define USERS_H
#include<map>
#include<QString>

using namespace std;

class Users
{
private:
    map<QString, int> registeredUsers;

public:
    Users();

    void addUser(QString n, int pass);


    void removeUser(QString n);

    bool findUser(QString n, int p);

    void editUser(QString oldName, QString editedName, int editedValue);

    void editUserName(QString oldName, QString editedName);

    void editUserPassword(QString name, int editedValue);
};

#endif // USERS_H
