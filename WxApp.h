#pragma once

#include <wx/wx.h>
#include <wx/toolbar.h>
#include <wx/artprov.h>
#include <wx/aui/aui.h>
#include <wx/aui/framemanager.h>
#include <wx/spinctrl.h>

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);
    ~MyFrame();
    wxAuiDockArt* GetDockArt();
    wxAuiNotebook* CreateNotebook();
    //wxSizeReportCtrl* CreateSizeReportCtrl(const wxSize& size = wxWindow::FromDIP(wxSize(80, 80), NULL));

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    wxAuiManager m_mgr;
};

enum
{
    ID_Hello = 1
};
