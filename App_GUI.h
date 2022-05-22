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
private:
    void OnClick(wxCommandEvent& event);
    void signInPage();
    void signUpPage();

    wxDECLARE_EVENT_TABLE();
};