#include "WorkFile.h"

WorkFile::WorkFile()
{
	Values = gcnew List<Row^>();
    FileName = L"Безымянный";
	IsNew = true;
    IsChanged = false;
}


//Функция дли сохранения файла
void WorkFile::saveFile(String^ f_name)
{
    IO::FileStream^ file = IO::File::Create(f_name); //Открытие файла
        //Преобразование Values в csv и запись в файл
    for (int i = 0; i < Values->Count; i++) {
        String^ line = Values[i]->ToCsvString();
        array<unsigned char>^ bytes = System::Text::Encoding::UTF8->GetBytes(line);
        file->Write(bytes, 0, bytes->Length);
    }
    delete (IDisposable^)file;
    IsNew = false;
    IsChanged = false;
    FileName = f_name;
}
