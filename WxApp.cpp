#include "WxApp.h"
#include "tipicon.xpm"
#include "spinctrl2.cpp"
//using namespace std;

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("mx_media_demo");
    frame->Show(true);
    //frame->ShowFullScreen(true);

    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{

    SetIcon(wxIcon(tipicon_xpm));

    wxMenuBar* menuBar = new wxMenuBar;
    
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);
    
    wxToolBar* toolbar = CreateToolBar(wxTB_TEXT);
    // 添加工具按钮
    toolbar->AddTool(wxID_NEW, _("新建"), wxArtProvider::GetBitmap(wxART_NEW));
    toolbar->AddTool(wxID_OPEN, "打开", wxArtProvider::GetBitmap(wxART_FILE_OPEN));
    toolbar->AddSeparator();
    toolbar->AddTool(wxID_SAVE, "保存", wxArtProvider::GetBitmap(wxART_FILE_SAVE));
    toolbar->AddTool(wxID_EXIT, "退出", wxArtProvider::GetBitmap(wxART_QUIT), "这是退出按钮");


    // 设置自动布局
    toolbar->Realize();
    //toolbar->SetWindowStyleFlag(toolbar->GetWindowStyleFlag() | wxTB_FLOATER);
    Centre();

    CreateNotebook();
    // wxNotebook* notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

     //notebook->Thaw();



     //m_mgr.AddPane(notebook, wxLEFT, "Pane Caption");





    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

MyFrame::~MyFrame() {};

wxAuiDockArt* MyFrame::GetDockArt()
{
    return m_mgr.GetArtProvider();
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

wxAuiNotebook* MyFrame::CreateNotebook()
{
    wxAuiNotebook* notebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(430, 200)), wxAUI_NB_DEFAULT_STYLE);

    wxPanel* panel_0 = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, "panel_0");
    wxPanel* window1 = new wxPanel(notebook, wxID_ANY);
    wxPanel* window2 = new wxPanel(notebook, wxID_ANY);
    wxPanel* window3 = new wxPanel(notebook, wxID_ANY);

    // wxBoxSizer* s1 = new wxBoxSizer(wxHORIZONTAL);
     //wxTextCtrl* text1 = new wxTextCtrl(panel_0, -1);
     //wxSpinCtrl* spinctrl = new wxSpinCtrl(panel_0, -1, "5", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS);


    wxButton* button = new wxButton(panel_0, -1, "");
    wxBitmap bitmap = wxArtProvider::GetBitmap(wxART_INFORMATION, wxART_OTHER, wxSize(16, 16));
    wxBitmapButton* bitmapButton = new wxBitmapButton(panel_0, -1, bitmap, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);


    wxFlexGridSizer* flex = new wxFlexGridSizer(4, 2, 0, 0);
    flex->Add(new wxStaticText(panel_0, -1, "wxTextCtrl:"), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxTextCtrl(panel_0, -1, "", wxDefaultPosition, FromDIP(wxSize(100, -1))), 1, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(button, 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(bitmapButton, 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxStaticText(panel_0, -1, "wxSpinCtrl:"), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxSpinCtrl(panel_0, -1, "5", wxDefaultPosition, wxDefaultSize,
        wxSP_ARROW_KEYS, 5, 50, 5), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));

    panel_0->SetSizer(flex);

    MyFloatSpinCtrl* floatSpinCtrl = new MyFloatSpinCtrl(window1);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(floatSpinCtrl, 0, wxEXPAND | wxALL, 10);
    window1->SetSizerAndFit(sizer);
    //wxGridSizer* grid_sizer = new wxGridSizer(2);
    //grid_sizer->SetHGap(10);
    //grid_sizer->Add(s1);

    notebook->AddPage(panel_0, "panel_0");
    notebook->AddPage(window1, "panel_1");
    notebook->AddPage(window2, "panel_2");
    notebook->AddPage(window3, "panel_3");

    return notebook;
}

