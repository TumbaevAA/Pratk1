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




//Загрузка MainForm
System::Void Prakt::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    _workFile = gcnew WorkFile();                                  //Указатель на объект класса WorkFile
    dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values); //Связь dataGridView и списка Values
    return System::Void ();
}




//Сохранить
System::Void Prakt::MainForm::button_save_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (_workFile == nullptr) return; //Если файл не создан, кнопка не активна


    if (_workFile->IsNew)
    { 
        if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //Вызов диалога с выбором директории и имени файла
        {
            _workFile->FileName = saveFileDialog1->FileName;           //Сохранение пути в FileName

            saveFile(_workFile);
        }
    }

    else
    {
        saveFile(_workFile);
    }

    return System::Void();
}




//Создать
System::Void Prakt::MainForm::button_create_Click(System::Object^ sender, System::EventArgs^ e)
{
    _workFile = gcnew WorkFile();                              //Указатель на объект класса WorkFile
    dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values); //Связь dataGridView и списка Values

    return System::Void();
}




//Открыть
System::Void Prakt::MainForm::button_open_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //Вызов диалога с выбором директории и имени файла
    {
        StreamReader^ file = File::OpenText(openFileDialog1->FileName);
        try
        {
            _workFile = gcnew WorkFile();                          //Указатель на объект класса WorkFile
            _workFile->FileName = openFileDialog1->FileName;       //Сохранение пути в FileName

            auto line = file->ReadLine();
            while (line != nullptr) {
                _workFile->Values->Add(gcnew Row(line));
                line = file->ReadLine();
            }

            dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values);
        }
        finally
        {
            delete (IDisposable^)file;
            _workFile->IsNew = false;
        } 
    }
    return System::Void();
}




//Сохранить как
System::Void Prakt::MainForm::button_saveas_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (_workFile == nullptr) return;                                 //Если файл не создан, кнопка не активна

    if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //Вызов диалога с выбором директории и имени файла
    {

        _workFile->FileName = saveFileDialog1->FileName;           //Сохранение пути в FileName

        saveFile(_workFile);
    }

    return System::Void();
}


//Удалить
System::Void Prakt::MainForm::button_del_Click(System::Object^ sender, System::EventArgs^ e)
{
    int index = dataGridView1->CurrentRow->Index;
    dataGridView1->Rows->Remove(dataGridView1->Rows[index]);


    return System::Void();
}


//Выход
System::Void Prakt::MainForm::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show(this, L"Вы действительно хотите выйти?", "MainForm", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) Close();

    return System::Void();
}




//Функция для сохранения файла
void Prakt::saveFile(WorkFile ^ _workFile)
{
    using namespace IO;

    FileStream^ file = File::Create(_workFile->FileName); //Открытие файла
    try
    {
        //Преобразование Values в csv и запись в файл
        for (int i = 0; i < _workFile->Values->Count; i++) {
            auto line = _workFile->Values[i]->ToCsvString();
            auto bytes = System::Text::Encoding::UTF8->GetBytes(line);
            file->Write(bytes, 0, bytes->Length);
        }
    }
    finally
    {
        delete (IDisposable^)file;
        _workFile->IsNew = false;
    }
}
