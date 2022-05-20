#include <wx/wxprec.h>
 
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
    MyFrame(const wxString &title);
 
private:
    void OnClick(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};