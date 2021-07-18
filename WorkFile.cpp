#include "WorkFile.h"

WorkFile::WorkFile()
{
	Values = gcnew List<Row^>();
    FileName = L"����������";
	IsNew = true;
    IsChanged = false;
}


//������� ��� ���������� �����
void WorkFile::saveFile(String^ f_name)
{
    IO::FileStream^ file = IO::File::Create(f_name); //�������� �����
        //�������������� Values � csv � ������ � ����
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
