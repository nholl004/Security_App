#include <fstream>

#include "userProfile.h"

userProfile::userProfile(){}
userProfile::userProfile(wxString email, wxString name="", wxString date="" )
{
    this.email = email;
    this.fullName = name;
    this.birthday = date;
}

wxString userProfile::getFullName(){return this.fullName;}
wxString userProfile::getBirthday(){return this.birthday;}
wxString userProfile::getEmail(){return this.email;}

void userProfile::setFullName(wxString name)
{
    this.fullName = name;
}
void userProfile::setBirthday(wxString date)
{
    this.birthday = date;
}
void userProfile::changeEmail(wxString newEmail)
{
    this.email = newEmail;

    std::string pass;//password hold

    std::ifstream in;
    std::string line;
    in.open("data.txt");
    if(in.is_open()){
        while(std::getline(in,line)){

            std::string e = line.substr(0,line.find("%"));
            line.erase(0, line.find("%")+1);
            std::string p = line;

            if(email.ToStdString() == e)
                pass = p;
                break;

        }
        in.close();
    }
    std::ofstream out;
    out.open ("data.txt",std::ios_base::app);
    if(out.is_open()){
        out << newEmail.ToStdString()+ "%"+
            pass<< std::endl;
    }
    out.close();
}