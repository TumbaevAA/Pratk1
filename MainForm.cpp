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

    //Связь textbox'ов и свойств _searchRow
    _searchRow = gcnew SearchRow();
    textBox_comp->DataBindings->Add(gcnew Binding("Text", _searchRow, "comp"));
    textBox_add->DataBindings->Add(gcnew Binding("Text", _searchRow, "add"));
    textBox_post->DataBindings->Add(gcnew Binding("Text", _searchRow, "post"));
    textBox_sal->DataBindings->Add(gcnew Binding("Text", _searchRow, "sal"));
    comboBox_edu->DataBindings->Add(gcnew Binding("Text", _searchRow, "edu"));
    maskedTextBox_exp->DataBindings->Add(gcnew Binding("Text", _searchRow, "exp"));
    comboBox_cond->DataBindings->Add(gcnew Binding("Text", _searchRow, "cond"));

    return System::Void();
}


//Сохранить
System::Void Prakt::MainForm::button_save_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    //Если файл новый
    if (_workFile->IsNew)
    { 
        if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //Вызов диалога с выбором директории и имени файла
        {

            try
            {
                _workFile->saveFile(saveFileDialog1->FileName);
                _workFile->FileName = saveFileDialog1->FileName;           //Сохранение пути в FileName
                this->Text = Path::GetFileName(_workFile->FileName) + L" - Список вакансий";   //Вывод имени файла в заголовок формы
                
            }
            catch (Exception^ e)
            {
                MessageBox::Show(L"Не удалось сохранить файл");
            }
        }
    }

    //Если файл старый
    else
    {
        try
        {
            _workFile->saveFile(_workFile->FileName);
            this->Text = Path::GetFileName(_workFile->FileName) + L" - Список вакансий";   //Вывод имени файла в заголовок формы
        }
        catch (Exception^ e)
        {
            MessageBox::Show(L"Не удалось сохранить файл");
        }
    }

    return System::Void();
}


//Создать
System::Void Prakt::MainForm::button_create_Click(System::Object^ sender, System::EventArgs^ e)
{
    //Нужно ли сохранить изменеия в старом файле
    if (_workFile->IsChanged)
    {
        this->DialogResult = MessageBox::Show(L"Сохранить старый файл перед созданием нового?", L"Создать", MessageBoxButtons::YesNoCancel);
        if (this->DialogResult == Windows::Forms::DialogResult::Cancel)
            return System::Void();
        else if (this->DialogResult == Windows::Forms::DialogResult::Yes)
            this->button_save_Click(sender, e);
        else if (this->DialogResult == Windows::Forms::DialogResult::No);

    }


    _workFile = gcnew WorkFile();                              //Указатель на объект класса WorkFile
    dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values); //Связь dataGridView и списка Values
    this->Text = _workFile->FileName + L" - Список вакансий";

    return System::Void();
}


//Открыть
System::Void Prakt::MainForm::button_open_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //Вызов диалога с выбором директории и имени файла
    {
        //Проверка на формат файла
        try
        {
            StreamReader^ file = File::OpenText(openFileDialog1->FileName);

            Row^ row = gcnew Row();
            String^ line = file->ReadLine();
            while (line != nullptr)
            {
                if (row->parseLine(line, false) == false)
                {
                    MessageBox::Show(L"Неверный формат файла");
                    return System::Void();
                }
                line = file->ReadLine();
            }
            delete(Row^)row;
            delete (IDisposable^)file;
        }
        catch (Exception^ e)
        {
            MessageBox::Show(L"Не удалось открыть файл");
        }

        //Открытие файла
        try
        {
            StreamReader^ file = File::OpenText(openFileDialog1->FileName);
           
            _workFile = gcnew WorkFile();                          
            String^ line = file->ReadLine();
            while (line != nullptr)
            {
                _workFile->Values->Add(gcnew Row(line));
                line = file->ReadLine();
            }
            delete (IDisposable^)file;

            dataGridView1->DataSource = gcnew BindingList<Row^>(_workFile->Values);
            _workFile->FileName = openFileDialog1->FileName;       //Сохранение пути в FileName
            _workFile->IsNew = false;
            this->Text = Path::GetFileName(_workFile->FileName) + L" - Список вакансий";   //Вывод имени файла в заголовок формы
        }
        catch (Exception^ e)
        {
            MessageBox::Show(L"Не удалось открыть файл");
        }
    }
    return System::Void();
}


//Сохранить как
System::Void Prakt::MainForm::button_saveas_Click(System::Object^ sender, System::EventArgs^ e)
{

    if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)    //Вызов диалога с выбором директории и имени файла
    {
        try
        {
            _workFile->saveFile(saveFileDialog1->FileName);
            this->Text = Path::GetFileName(_workFile->FileName) + L" - Список вакансий";   //Вывод имени файла в заголовок формы
        }
        catch (Exception^ e)
        {
            MessageBox::Show(L"Не удалось сохранить файл");
        }
    }

    return System::Void();
}


//Удалить строку
System::Void Prakt::MainForm::button_del_Click(System::Object^ sender, System::EventArgs^ e)
{
    int index = dataGridView1->CurrentRow->Index;
    if (MessageBox::Show(L"Вы действительно хотите удалить строку?", L"Удалить строку", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
    { 
        try
        {
            dataGridView1->Rows->Remove(dataGridView1->Rows[index]);
            _workFile->IsChanged = true;
            this->Text = Path::GetFileName(_workFile->FileName) + "*" + L" - Список вакансий";
        }
        catch (InvalidOperationException^) //Не позволяет удалить пустую строку
        {
            return System::Void();
        }   
    }
    return System::Void();
}


//Выход
System::Void Prakt::MainForm::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

//Введено невозможное значение
System::Void Prakt::MainForm::dataGridView1_DataError(System::Object^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e)
{
    MessageBox::Show(L"Введено невозможное значение");
    return System::Void();
}


//Закртыие формы
System::Void Prakt::MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{ 
    if (_workFile->IsChanged)
    {
        this->DialogResult = MessageBox::Show(L"Сохранить файл перед выходом?", L"Выход", MessageBoxButtons::YesNoCancel);

        if (this->DialogResult == Windows::Forms::DialogResult::Yes)
            this->button_save_Click(sender,e);
        else if (this->DialogResult == Windows::Forms::DialogResult::No)
            e->Cancel = false;
        else if (this->DialogResult == Windows::Forms::DialogResult::Cancel)
            e->Cancel = true;
    }
    
    else
        e->Cancel = false;

    return System::Void();
}




//Поиск
System::Void Prakt::MainForm::button_search_Click(System::Object^ sender, System::EventArgs^ e)
{
    //Проверка на правильно введенную зарплату
    Decimal f;
    if (_searchRow->sal == "" || _searchRow->sal == nullptr ||
        Decimal::TryParse(textBox_sal->Text, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowDecimalPoint, CultureInfo::InstalledUICulture, f))
    {
        
        dataGridView1->CurrentCell = nullptr;
        for (int i = 0; i < _workFile->Values->Count; i++)
            if (_searchRow->comp != "" && _searchRow->comp != nullptr  && _searchRow->comp != _workFile->Values[i]->comp ||
                _searchRow->add != "" && _searchRow->add != nullptr && _searchRow->add != _workFile->Values[i]->add ||
                _searchRow->post != "" && _searchRow->post != nullptr && _searchRow->post != _workFile->Values[i]->post ||
                _searchRow->compareSal(_workFile->Values[i]->sal) ||
                _searchRow->edu != "" && _searchRow->edu != nullptr && _searchRow->edu != _workFile->Values[i]->edu ||
                _searchRow->compareExp(_workFile->Values[i]->exp) ||
                _searchRow->cond != "" && _searchRow->cond != nullptr && _searchRow->cond != _workFile->Values[i]->cond)
                dataGridView1->Rows[i]->Visible = false;
    }

    else
    {
        _searchRow->sal = nullptr;
        MessageBox::Show(L"Зарплата введена неверно");
    }
    
    return System::Void();
}


//Отменить поиск
System::Void Prakt::MainForm::button_cancelsearch_Click(System::Object^ sender, System::EventArgs^ e)
{
    _searchRow->edu = nullptr;
    comboBox_edu->Text = nullptr;
    _searchRow->cond = nullptr;
    comboBox_cond->Text = nullptr;
    for (int i = 0; i < _workFile->Values->Count; i++)
        dataGridView1->Rows[i]->Visible = true;

    return System::Void();
}



//Изменение значения в ячейке
System::Void Prakt::MainForm::dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (_workFile != nullptr)
    {
        _workFile->IsChanged = true;
        this->Text = Path::GetFileName(_workFile->FileName) + "*" + L" - Список вакансий";
    }
    return System::Void();
}