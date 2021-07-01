#pragma once

#include "Row.h"

using namespace System;
using namespace System::Collections::Generic;

ref class WorkFile
{
public:
	WorkFile();
	
	property String^ FileName;       //Имя файла
	property List<Row^>^ Values;     //Список со значениями  
	property bool IsNew;
};

