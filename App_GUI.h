#include <wx/wxprec.h>
#include "wx/simplebook.h"
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow *p, wxWindowID id, const wxString &title);
    wxSimplebook *tabs;
    wxTextCtrl *emailData;
    wxTextCtrl *passwordData;
    wxTextCtrl *passwordDataV;
private:
    void OnClick(wxCommandEvent& event);
    void sUpUpdateUI(wxUpdateUIEvent& event);
    void sInUpdateUI(wxUpdateUIEvent& event);

    bool validCreds();
    
    void homePage();
    void signInPage();
    void signUpPage();
    void userProfilePage(wxString email);

    wxDECLARE_EVENT_TABLE();
};