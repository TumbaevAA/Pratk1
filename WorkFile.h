#pragma once

#include "Row.h"

using namespace System;
using namespace System::Collections::Generic;

ref class WorkFile
{
public:
	WorkFile();
	
	property String^ FileName;       //��� �����
	property List<Row^>^ Values;     //������ �� ����������  
	property bool IsNew;
};

