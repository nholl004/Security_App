#include <iostream>

#ifndef CLASS_USER
#define CLASS_USER

class account{
private:
    std::string username;
    std::string password;
public:
    account();
    void setUsername(std::string username_info);
    void setPassword(std::string password_info);

    account signUp();
    account signIn();

    void print_info();
};

#endif