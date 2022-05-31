#include <iostream>
#include <wx/wxprec.h>



class userProfile
{
private:
    wxString fullName;
    wxString email;
    wxString birthday;
public:
    userProfile();
    userProfile(wxString email, wxString name = "", wxString date = "" );
    
    wxString getFullName();
    wxString getBirthday();
    wxString getEmail();
    
    void setFullName(wxString name);
    void setBirthday(wxString date);
    void changeEmail(wxString newEmail);
};