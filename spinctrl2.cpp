#include <wx/wx.h>
#include <wx/artprov.h>

class MyFloatSpinCtrl : public wxPanel
{
public:
    MyFloatSpinCtrl(wxWindow* parent, wxWindowID id = wxID_ANY)
        : wxPanel(parent, id)
    {
        // 创建控件
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

        // 创建文本框用于显示和编辑数字
        numberInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
        sizer->Add(numberInput, 1, wxEXPAND | wxALL, 5);

        // 创建垂直布局的增减按钮
        wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
        wxBitmap upArrowBitmap = wxArtProvider::GetBitmap(wxART_GO_UP, wxART_BUTTON);
        wxBitmap downArrowBitmap = wxArtProvider::GetBitmap(wxART_GO_DOWN, wxART_BUTTON);
        upButton = new wxBitmapButton(this, wxID_ANY, upArrowBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
        downButton = new wxBitmapButton(this, wxID_ANY, downArrowBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
        buttonSizer->Add(upButton, 0, wxEXPAND | wxALL, 5);
        buttonSizer->Add(downButton, 0, wxEXPAND | wxALL, 5);

        sizer->Add(buttonSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

        // 绑定按钮事件
        upButton->Bind(wxEVT_BUTTON, &MyFloatSpinCtrl::OnUpButtonClick, this);
        downButton->Bind(wxEVT_BUTTON, &MyFloatSpinCtrl::OnDownButtonClick, this);

        SetSizerAndFit(sizer);
    }

    // 获取当前值
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
        SetValue(currentValue + 1.0); // 这里增加 0.1，可以根据需要调整增减步长
    }

    void OnDownButtonClick(wxCommandEvent& event)
    {
        double currentValue = GetValue();
        SetValue(currentValue - 1.0); // 这里减少 0.1，可以根据需要调整增减步长
    }

    void SetValue(double value)
    {
        numberInput->ChangeValue(wxString::Format("%.2f", value)); // 保留两位小数
    }
};