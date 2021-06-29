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

//Сохранить
System::Void Prakt::MainForm::button_save_Click(System::Object^ sender, System::EventArgs^ e)
{
   
    if (_workFile == nullptr) return; //Если файл не создан, кнопка не активна



    FileStream^ file = File::OpenWrite(_workFile->FileName);

    //Преобразование Values в csv и запись в файл
    for (int i = 0; i < _workFile->Values->Count; i++) {
   	auto line = _workFile->Values[i]->ToCsvString();
    file->Write(_encoding->GetBytes(line), 0, line->Length);
    }

    file->Close();


    return System::Void();
}

//СОздать
System::Void Prakt::MainForm::button_create_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //Вызов диалога с выбором директории и имени файла
    {
        //Создание файла
        FileStream^ file = File::Create(saveFileDialog1->FileName);
        file->Close();

        
        _workFile = gcnew WorkFile();                              //Указатель на объект класса WorkFile
        _workFile->FileName = saveFileDialog1->FileName;           //Сохранение пути в FileName
        dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values); //Связь dataGridView и списка Values

    }
    return System::Void();
}
