#include "App_GUI.h"


enum IDs
{
    ID_Hello = wxID_LAST + 1,
    ID_Frame1,
    ID_Frame2,
    ID_SignUp,
    ID_SignIn,
    ID_Home
};

wxIMPLEMENT_APP(MyApp);

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnClick)
wxEND_EVENT_TABLE()

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame(NULL, ID_Frame1, "Security App");
    frame->Show(true);

    return true;
}

MyFrame::MyFrame(wxWindow *p ,wxWindowID id,const wxString &title) : wxFrame(p, id, title, wxDefaultPosition, wxSize(450,350))
{
    tabs = new wxSimplebook(this);

    wxPanel *panel = new wxPanel(tabs);
    
    wxBoxSizer *col1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *row2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *row3 = new wxBoxSizer(wxHORIZONTAL);
    
    row1->Add(new wxStaticText(panel, wxID_ANY, 
        "Welcome to my Security App!"),0,wxALIGN_CENTER | wxTOP,70);
    row2->Add(new wxStaticText(panel, wxID_ANY, 
        "Please sign in or sign up."),0,wxALIGN_CENTER | wxBOTTOM,25);
    row3->Add(new wxButton(panel, ID_SignIn, "Sign In" ), 0, wxALL, 10);
    row3->Add(new wxButton(panel, ID_SignUp, "Sign Up" ), 0, wxALL, 10);

    col1->Add(row1, 0, wxALIGN_CENTER, 10);
    col1->Add(row2, 0, wxALIGN_CENTER, 10);
    col1->Add(row3,0, wxALIGN_CENTER, 10);

    panel->SetSizer(col1);
    
    tabs->InsertPage( 0, panel, "Home", true );

}
void MyFrame::signInPage()
{
    wxPanel *panel = new wxPanel(tabs);
    
    //wxButton *btn = new wxButton(panel, ID_SignUp, "Go to home page", wxPoint(10,10));
    wxBoxSizer *col = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *row_t1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *title1 =  new wxStaticText(panel, wxID_ANY, 
        wxT("Sign in to"));
    wxBoxSizer *row_t2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *title2 =  new wxStaticText(panel, wxID_ANY, 
        wxT("your account"));

    row_t1->Add(title1, 1);
    row_t2->Add(title2, 1);
    col->Add(row_t1, 0,wxALIGN_CENTER | wxTOP, 10);
    col->Add(row_t2, 0,wxALIGN_CENTER | wxBOTTOM, 10);

    wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *emailRq =  new wxStaticText(panel, wxID_ANY, 
        wxT("Enter Email: "));

    row1->Add(emailRq, 0, wxLEFT | wxRIGHT, 24);
    wxTextCtrl *emailData = new wxTextCtrl(panel, wxID_ANY);
    row1->Add(emailData, 1);
    col->Add(row1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *passwordRq = new wxStaticText(panel, wxID_ANY, 
        wxT("Enter Password:"));

    row2->Add(passwordRq, 0, wxRIGHT, 25);
    wxTextCtrl *passwordData = new wxTextCtrl(panel, wxID_ANY);
    row2->Add(passwordData, 1);
    col->Add(row2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    panel->SetSizer(col);

    tabs->InsertPage( 1, panel, "Sign In" );
}

void MyFrame::signUpPage()
{
    wxPanel *signUpPg = new wxPanel(tabs);
    
    //wxButton *btn = new wxButton(panel, ID_SignUp, "Go to home page", wxPoint(10,10));
    wxBoxSizer *col = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *row_t1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *title1 =  new wxStaticText(signUpPg, wxID_ANY, 
        wxT("Sign up for"));
    wxBoxSizer *row_t2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *title2 =  new wxStaticText(signUpPg, wxID_ANY, 
        wxT("your account"));

    row_t1->Add(title1, 1);
    row_t2->Add(title2, 1);
    col->Add(row_t1, 0,wxALIGN_CENTER | wxTOP, 10);
    col->Add(row_t2, 0,wxALIGN_CENTER | wxBOTTOM, 10);

    wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *emailRq =  new wxStaticText(signUpPg, wxID_ANY, 
        wxT("Enter Email: "));

    row1->Add(emailRq, 0, wxLEFT | wxRIGHT, 24);
    wxTextCtrl *emailData = new wxTextCtrl(signUpPg, wxID_ANY);
    row1->Add(emailData, 1);
    col->Add(row1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *passwordRq = new wxStaticText(signUpPg, wxID_ANY, 
        wxT("Enter Password:"));

    row2->Add(passwordRq, 0, wxRIGHT, 25);
    wxTextCtrl *passwordData = new wxTextCtrl(signUpPg, wxID_ANY);
    row2->Add(passwordData, 1);
    col->Add(row2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row3 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *passwordVRq = new wxStaticText(signUpPg, wxID_ANY, 
        wxT("Verify Password:"));

    row3->Add(passwordVRq, 0, wxRIGHT, 25);
    wxTextCtrl *passwordDataV = new wxTextCtrl(signUpPg, wxID_ANY);
    row2->Add(passwordDataV, 1);
    col->Add(row2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    signUpPg->SetSizer(col);

    tabs->InsertPage( 2, signUpPg, "Sign Up");
}

void MyFrame::OnClick(wxCommandEvent& event)
{
    switch( event.GetId() )
    {
        case ID_SignIn:
            signInPage();
            tabs->ChangeSelection(1);
            break;

        case ID_SignUp:
            signUpPage();
            tabs->ChangeSelection(2);
            break;

        case ID_Home:
            tabs->ChangeSelection(0);
            break;

        default:
            event.Skip();
    }
}