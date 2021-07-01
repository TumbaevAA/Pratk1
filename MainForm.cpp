#include "MainForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Prakt::MainForm form;
    Application::Run(% form);
}


//�������� MainForm
System::Void Prakt::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    _workFile = gcnew WorkFile();                                  //��������� �� ������ ������ WorkFile
    dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values); //����� dataGridView � ������ Values
    return System::Void ();
}




//���������
System::Void Prakt::MainForm::button_save_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (_workFile == nullptr) return; //���� ���� �� ������, ������ �� �������

    if (_workFile->IsNew)
        if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //����� ������� � ������� ���������� � ����� �����
        {
            FileStream^ file = File::Create(saveFileDialog1->FileName); //�������� �����
            try
            {
                _workFile->FileName = saveFileDialog1->FileName;           //���������� ���� � FileName

                //�������������� Values � csv � ������ � ����
                for (int i = 0; i < _workFile->Values->Count; i++) {
                    auto line = _workFile->Values[i]->ToCsvString();
                    file->Write(_encoding->GetBytes(line), 0, line->Length);
                }
            }
            finally
            {
                if (file)
                    delete (IDisposable^)file;
                _workFile->IsNew = false;
            }
        }

    if (_workFile->IsNew == false)
    {
        FileStream^ file = File::Create(_workFile->FileName); //�������� �����
        try
        {
            //�������������� Values � csv � ������ � ����
            for (int i = 0; i < _workFile->Values->Count; i++) {
                auto line = _workFile->Values[i]->ToCsvString();
                file->Write(_encoding->GetBytes(line), 0, line->Length);
            }
        }
        finally
        {
            if (file)
                delete (IDisposable^)file;
        }
           
    }

    return System::Void();
}




//�������
System::Void Prakt::MainForm::button_create_Click(System::Object^ sender, System::EventArgs^ e)
{
    _workFile = gcnew WorkFile();                              //��������� �� ������ ������ WorkFile
    dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values); //����� dataGridView � ������ Values

    return System::Void();
}




//�������
System::Void Prakt::MainForm::button_open_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //����� ������� � ������� ���������� � ����� �����
    {
        StreamReader^ file = File::OpenText(openFileDialog1->FileName);
        try
        {
            _workFile = gcnew WorkFile();                          //��������� �� ������ ������ WorkFile
            _workFile->FileName = openFileDialog1->FileName;       //���������� ���� � FileName

            auto line = file->ReadLine();
            while (line != nullptr) {
                _workFile->Values->Add(gcnew Row(line));
                line = file->ReadLine();
            }

            dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values);
        }
        finally
        {
            if (file)
                delete (IDisposable^)file;
            _workFile->IsNew = false;
        }

       
    }
    return System::Void();
}




//��������� ���
System::Void Prakt::MainForm::button_saveas_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (_workFile == nullptr) return; //���� ���� �� ������, ������ �� �������

    if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //����� ������� � ������� ���������� � ����� �����
    {
        FileStream^ file = File::Create(saveFileDialog1->FileName); //�������� �����
        try
        {
            _workFile->FileName = saveFileDialog1->FileName;           //���������� ���� � FileName

            //�������������� Values � csv � ������ � ����
            for (int i = 0; i < _workFile->Values->Count; i++) {
                auto line = _workFile->Values[i]->ToCsvString();
                file->Write(_encoding->GetBytes(line), 0, line->Length);
            }
        }
        finally
        {
            if (file)
                delete (IDisposable^)file;
            _workFile->IsNew = false;
        }
    }

   
    return System::Void();
}


//�������
System::Void Prakt::MainForm::button_del_Click(System::Object^ sender, System::EventArgs^ e)
{
    int a = dataGridView1->CurrentRow->Index;
    dataGridView1->Rows->Remove(dataGridView1->Rows[a]);


    return System::Void();
}


//�����
System::Void Prakt::MainForm::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show(this, L"�� ������������� ������ �����?", "MainForm", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
        Close();
    }

    return System::Void();
}

