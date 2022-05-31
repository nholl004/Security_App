#include <fstream>
#include "App_GUI.h"
#include "userProfile.cpp"


enum IDs
{
    ID_Hello = wxID_LAST + 1,
    ID_Frame1,
    ID_Frame2,
    ID_SignUp,
    ID_SignIn,
    ID_Home,
    ID_OK_SignUp,
    ID_OK_SignIn
};

wxIMPLEMENT_APP(MyApp);

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnClick)
EVT_TEXT(wxID_ANY, MyFrame::OnClick)
EVT_UPDATE_UI(ID_OK_SignUp, MyFrame::sUpUpdateUI)
EVT_UPDATE_UI(ID_OK_SignIn, MyFrame::sInUpdateUI)
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
    homePage();
}

void MyFrame::homePage()
{
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
    
    tabs->ShowNewPage(panel);
}

void MyFrame::signInPage()
{
    wxPanel *signInPg = new wxPanel(tabs);
    
    //wxButton *btn = new wxButton(panel, ID_SignUp, "Go to home page", wxPoint(10,10));
    wxBoxSizer *col = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *row_t1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *title1 =  new wxStaticText(signInPg, wxID_ANY, 
        wxT("Sign in to"));
    wxBoxSizer *row_t2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *title2 =  new wxStaticText(signInPg, wxID_ANY, 
        wxT("your account"));

    row_t1->Add(title1, 1);
    row_t2->Add(title2, 1);
    col->Add(row_t1, 0,wxALIGN_CENTER | wxTOP, 10);
    col->Add(row_t2, 0,wxALIGN_CENTER | wxBOTTOM, 10);

    wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *emailRq =  new wxStaticText(signInPg, wxID_ANY, 
        wxT("Enter Email: "));

    row1->Add(emailRq, 0, wxLEFT | wxRIGHT, 24);
    emailData = new wxTextCtrl(signInPg, wxID_ANY);
    row1->Add(emailData, 1);
    col->Add(row1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *passwordRq = new wxStaticText(signInPg, wxID_ANY, 
        wxT("Enter Password:"));

    row2->Add(passwordRq, 0, wxRIGHT, 25);
    passwordData = new wxTextCtrl(signInPg, wxID_ANY);
    row2->Add(passwordData, 1);
    col->Add(row2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row3 = new wxBoxSizer(wxHORIZONTAL);
    row3->Add(new wxButton(signInPg, ID_OK_SignIn, "OK" ), 0, wxALL , 10);
    row3->Add(new wxButton(signInPg, ID_Home, "Cancel" ), 0, wxALL , 10);
    col->Add(row3, 0, wxALIGN_RIGHT);

    signInPg->SetSizer(col);

    tabs->ShowNewPage(signInPg);
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
    emailData = new wxTextCtrl(signUpPg, wxID_ANY);
    row1->Add(emailData, 1);
    col->Add(row1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *passwordRq = new wxStaticText(signUpPg, wxID_ANY, 
        wxT("Enter Password:"));

    row2->Add(passwordRq, 0, wxRIGHT, 26);
    passwordData = new wxTextCtrl(signUpPg, wxID_ANY);
    row2->Add(passwordData, 1);
    col->Add(row2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row3 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *passwordVRq = new wxStaticText(signUpPg, wxID_ANY, 
        wxT("Verify Password:"));

    row3->Add(passwordVRq, 0, wxRIGHT, 24);
    passwordDataV = new wxTextCtrl(signUpPg, wxID_ANY);
    row3->Add(passwordDataV, 1);
    col->Add(row3, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *row4 = new wxBoxSizer(wxHORIZONTAL);
    row4->Add(new wxButton(signUpPg, ID_OK_SignUp, "OK" ), 0, wxALL, 10);
    row4->Add(new wxButton(signUpPg, ID_Home, "Cancel" ), 0, wxALL, 10);
    col->Add(row4, 0, wxALIGN_RIGHT);

    signUpPg->SetSizer(col);

    tabs->ShowNewPage(signUpPg);
}

void MyFrame::userProfilePage(wxString email)
{
    //establish profile class;
    userProfile *user = new userProfile(email);
    std::cout << user->getEmail()+"/"+user->getFullName()+"/"+user->getBirthday()<<std::endl;

    wxPanel *userPg = new wxPanel(tabs);
    
    //wxButton *btn = new wxButton(panel, ID_SignUp, "Go to home page", wxPoint(10,10));
    wxBoxSizer *col = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *row_t1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *title =  new wxStaticText(userPg, wxID_ANY, 
        wxT("Profile Page"));

    row_t1->Add(title, 1);
    col->Add(row_t1, 0,wxALIGN_CENTER | wxALL, 10);

    wxBoxSizer *rowFullName = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *userNameTitle = new wxStaticText(userPg, wxID_ANY, 
        wxT("Full Name: "));

    rowFullName->Add(userNameTitle, 1);
    col->Add(rowFullName,0,wxALIGN_LEFT | wxALL,10);

    wxBoxSizer *rowEmail = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *userEmailTitle = new wxStaticText(userPg, wxID_ANY, 
        wxT("Email: "));

    rowEmail->Add(userEmailTitle, 1);
    col->Add(rowEmail,0,wxALIGN_LEFT | wxALL,10);

    wxBoxSizer *rowBirth = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *userBirthTitle = new wxStaticText(userPg, wxID_ANY, 
        wxT("Birthday: "));

    rowBirth->Add(userBirthTitle, 0, wxALIGN_LEFT);
    col->Add(rowBirth,0,wxALIGN_LEFT | wxALL,10);

    userPg->SetSizer(col);

    tabs->ShowNewPage(userPg);
    user->~userProfile();
}

//What Does it do:
//Checks for valid email @
//ToDos:
//Need to check if email was used
bool emailValid(wxString email)
{
    email.LowerCase();
    
    std::string yahoo = "@yahoo.com";
    std::string eMail = "@email.com";
    std::string iCloud = "@icloud.com";
    std::string gmail = "@gmail.com"; 
    std::string e = email.ToStdString();

    if(e.find(yahoo)!=std::string::npos) return true;
    else if(e.find(eMail)!=std::string::npos) return true;
    else if(e.find(iCloud)!=std::string::npos) return true;
    else if(e.find(gmail)!=std::string::npos) return true;
    else return false;
}
//What Does it do:
//Checks size of password is 8 or greater
//ToDos:
//use ascii to check characters (',.><123abc ... etc)
bool passwordValid(wxString pass){
    std::string p = pass.ToStdString();
    if(p.size() > 7)return true;
    else return false; 
}

void MyFrame::OnClick(wxCommandEvent& event)
{
    std::ofstream out;
    switch( event.GetId() )
    {
        case ID_SignIn:
        //btn that sends user to sign in page
            signInPage();
            break;

        case ID_SignUp:
        //btn that sends user to sign up page
            signUpPage();
            break;

        case ID_Home:
        //btn that return to home page
            homePage();
            break;

        case ID_OK_SignUp:
        //OK btn takes data from text ctrl if data is valid and not empty,
        //then stores it to db or txt file upon sign up.
            
            out.open ("data.txt",std::ios_base::app);
            if(out.is_open()){
                out << emailData->GetValue()+ "%"+
                    passwordData->GetValue()<< std::endl;
            }
            out.close();

            homePage();
            break;

        case ID_OK_SignIn:
            //btn that validates a user in db or txt file
            //then will log user into secure page
            if(validCreds())
                userProfilePage(emailData->GetValue());
            else 
                wxMessageBox("Incorrect email or password. Would you like to try again or make new account?");
            break;

        default:
            event.Skip();
    }
}

bool MyFrame::validCreds()
{
    std::ifstream in;
    std::string line;
    in.open("data.txt");
    if(in.is_open()){
        while(std::getline(in,line)){

            std::string e = line.substr(0,line.find("%"));
            line.erase(0, line.find("%")+1);
            std::string p = line;

            if(emailData->GetValue().ToStdString() == e &&
                passwordData->GetValue().ToStdString() == p)
                return true;

        }
        in.close();
    }
    return false;
}

void MyFrame::sUpUpdateUI(wxUpdateUIEvent& event)
{
    event.Enable(false);

    if(!emailData->GetValue().empty() && 
        !passwordData->GetValue().empty() && 
        !passwordDataV->GetValue().empty() &&
        emailValid(emailData->GetValue()) &&
        passwordValid(passwordData->GetValue()) &&
        (passwordData->GetValue() == passwordDataV->GetValue())){
            event.Enable(true);
    }
}
void MyFrame::sInUpdateUI(wxUpdateUIEvent& event)
{
    event.Enable(false);

    if(!emailData->GetValue().empty() && 
        !passwordData->GetValue().empty() && 
        emailValid(emailData->GetValue())){
            event.Enable(true);
    }
}