#include "App_GUI.h"

enum IDs
{
    ID_Hello = wxID_LAST + 1,
    ID_Frame
};

wxIMPLEMENT_APP(MyApp);

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnClick)
wxEND_EVENT_TABLE()

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Security App");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title) : wxFrame(NULL, ID_Frame, title, wxDefaultPosition, wxSize(450,350))
{
    wxPanel *panel = new wxPanel(this, ID_Frame);

    wxBoxSizer *col1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *row2 = new wxBoxSizer(wxHORIZONTAL);
    
    row1->Add(new wxStaticText(panel, wxID_ANY, "Welcome to my Security App!"),0,wxALIGN_CENTER_VERTICAL|wxTOP,10);
    //horizontal->Add(new wxTextCtrl(panel,wxID_ANY),1);
    row2->Add(new wxStaticText(panel, wxID_ANY, "Please sign in or sign up."),0,wxALIGN_CENTER_VERTICAL|wxBOTTOM,10);
    
    col1->Add(row1, 0, wxALIGN_CENTER_HORIZONTAL, 10);
    col1->Add(row2, 0, wxALIGN_CENTER_HORIZONTAL, 10);

    panel->SetSizer(col1);

}
void MyFrame::OnClick(wxCommandEvent& event)
{
    if(event.GetId()==wxID_OK) SetClientSize(wxSize(400,450));
    if(event.GetId()==wxID_CANCEL) SetClientSize(wxSize(600,550));
}