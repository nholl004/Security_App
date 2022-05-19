#include <iostream>

#include "user_info/account.cpp"

#define DEBUG 1
#if DEBUG
#define print(x) std::cout << x << std::endl;
#else
#define print(x)
#endif

void sign_in_up(){
    std::string in;
    print("Would you like to sign in?(Type yes/no) ");
    std::cin >> in;
    if(in == "yes"){
        //call sign in function/class
        account user;
        user.signIn();
    }else if(in == "no"){
        //call sing up function/class
        print("Would you like to sign up?(Type yes/no) ");
        std::cin >> in;
        if(in == "yes"){
            account user;
            user.signUp();
            user.print_info();
        }
        else if(in == "no"){ print("Thank you for your time, good bye.");}
        else{throw std::invalid_argument("Incorrect insert. Please insert yes or no.");}

    }
    else
        throw std::invalid_argument("Incorrect insert. Please insert yes or no.");
    

}

int main(){
    
    try{
        sign_in_up();
    }
    catch (std::invalid_argument& e){
        std::cerr << e.what() << std::endl;
        return -1;
    }

    system("PAUSE");
    return 0;
}