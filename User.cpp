//
// Created by Irina on 12/6/2025.
//

#include "User.h"

int User::generalID = 1;

User :: User(const std :: string &first_name, const std :: string &last_name, const std :: string &email, const std :: string &role)
       : ID(generalID++), firstName(first_name), lastName(last_name), email(email), role(role) {}

//destructor
User :: ~User() = default;

//getteri
const std :: string & User :: getEmail() const { return email; }
const std :: string & User :: getRole() const { return role; }

//supraincarea operatorului de afisare
friend std :: ostream & User :: operator <<(std :: ostream &os, const User &obj) {
    return os << "ID: " << obj.ID
              << " | Name: " << obj.firstName << " " << obj.lastName
              << " | Email: " << obj.email
              << " | Role: " << obj.role;
}