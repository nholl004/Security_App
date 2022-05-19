#include <iostream>

#include "account.h"

#define DEBUG 1
#if DEBUG
#define print(x) std::cout << x << std::endl;
#else
#define print(x)
#endif

account::account(){
    this->username = "";
    this->password = "";
}
void account::setUsername(std::string username_info){
    this->username = username_info;
}
void account::setPassword(std::string password_info){
    this->password = password_info; 
}
void account::print_info(){
    std::cout<< "Username: " + this->username + "\nPassword: " + this->password << std::endl; 
}
account account::signUp(){
    std::string username_info, correct, password_tmp1, password_tmp2;

    print("What would you like your username to be?");
    std::cin >> username_info;
    print("Are you sure you want "+username_info+" to be your username?(Type yes/no)");;
    std::cin >> correct;

    while(correct != "yes"){
        print("What would you like your username to be?");
        std::cin >> username_info;
        print("Are you sure you want "+username_info+" to be your username?(Type yes/no)");
        std::cin >> correct;
    }

    this->setUsername(username_info);

    print("Please enter a password: ");
    std::cin >> password_tmp1;
    print("Please enter a password again:(just to verify) ");
    std::cin >> password_tmp2;

    while(password_tmp1 != password_tmp2){
        print("Password did not match. Please enter password again.");
        print("Please enter a password: ");
        std::cin >> password_tmp1;
        print("Please enter a password again:(just to verify) ");
        std::cin >> password_tmp2;
    }

    this->setPassword(password_tmp1);

    return *this;
}
account account::signIn(){
    std::string username_info,password_info;

    std::cout << "Please enter username: ";
    std::cin >> username_info;
    std::cout << "Please enter password: ";
    std::cin >> password_info;

    

    return *this;
}