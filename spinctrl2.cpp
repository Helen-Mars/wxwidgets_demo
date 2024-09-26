#include <wx/wx.h>
#include <wx/artprov.h>

class MyFloatSpinCtrl : public wxPanel
{
public:
    MyFloatSpinCtrl(wxWindow* parent, wxWindowID id = wxID_ANY)
        : wxPanel(parent, id)
    {
        // �����ؼ�
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

        // �����ı���������ʾ�ͱ༭����
        numberInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
        sizer->Add(numberInput, 1, wxEXPAND | wxALL, 5);

        // ������ֱ���ֵ�������ť
        wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
        wxBitmap upArrowBitmap = wxArtProvider::GetBitmap(wxART_GO_UP, wxART_BUTTON);
        wxBitmap downArrowBitmap = wxArtProvider::GetBitmap(wxART_GO_DOWN, wxART_BUTTON);
        upButton = new wxBitmapButton(this, wxID_ANY, upArrowBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
        downButton = new wxBitmapButton(this, wxID_ANY, downArrowBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
        buttonSizer->Add(upButton, 0, wxEXPAND | wxALL, 5);
        buttonSizer->Add(downButton, 0, wxEXPAND | wxALL, 5);

        sizer->Add(buttonSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

        // �󶨰�ť�¼�
        upButton->Bind(wxEVT_BUTTON, &MyFloatSpinCtrl::OnUpButtonClick, this);
        downButton->Bind(wxEVT_BUTTON, &MyFloatSpinCtrl::OnDownButtonClick, this);

        SetSizerAndFit(sizer);
    }

    // ��ȡ��ǰֵ
    double GetValue() const
    {
        double value;
        wxString numberStr = numberInput->GetValue();
        numberStr.ToDouble(&value);
        return value;
    }

private:
    wxTextCtrl* numberInput;
    wxBitmapButton* upButton;
    wxBitmapButton* downButton;

    void OnUpButtonClick(wxCommandEvent& event)
    {
        double currentValue = GetValue();
        SetValue(currentValue + 1.0); // �������� 0.1�����Ը�����Ҫ������������
    }

    void OnDownButtonClick(wxCommandEvent& event)
    {
        double currentValue = GetValue();
        SetValue(currentValue - 1.0); // ������� 0.1�����Ը�����Ҫ������������
    }

    void SetValue(double value)
    {
        numberInput->ChangeValue(wxString::Format("%.2f", value)); // ������λС��
    }
};