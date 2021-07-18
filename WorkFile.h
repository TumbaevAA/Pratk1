#pragma once

#include "Row.h"

using namespace System;
using namespace System::Collections::Generic;

ref class WorkFile
{
public:
	WorkFile();

	void saveFile(String^ f_name); //Сохранение файл
	
	property String^ FileName;       //Имя файла
	property List<Row^>^ Values;     //Список со значениями  
	property bool IsNew;         //Новый ли файл
	property bool IsChanged;        //Изменен ли файл
};

