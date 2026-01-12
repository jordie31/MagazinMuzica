#ifndef OOP_USER_H
#define OOP_USER_H
#include <string>
#include <iostream>

class User {
    static int generalID; // id pentru toate instantele obiectului
    const int ID;       // id personal instanta
    std :: string firstName;
    std :: string lastName;
    std :: string email;
    std :: string role; // angajat, administrator, cumparator

public :
    User(const std :: string &first_name, const std :: string &last_name, const std :: string &email, const std :: string &role);
   // const std :: string &getEmail() const;
    //const std :: string &getRole() const;

    friend std :: ostream &operator<<(std :: ostream &os, const User &obj);

    ~User();
    
};


#endif //OOP_USER_H