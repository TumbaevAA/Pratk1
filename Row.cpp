#include "Row.h"

Row::Row() {
	
}

Row::Row(String^ rowLine) {
	if (rowLine != nullptr) {
		parseLine(rowLine);
	}
}

String^ Row::ToCsvString() {
	return String::Join(";", gcnew array<String^>{comp, add, post, Convert::ToString(sal), edu, Convert::ToString(exp), cond}) + "\n";
}



Nullable<int> Row::ToNullableInt32(String^ str)
{
	if (str == "") return Nullable<int>();
	else return Nullable<int>(Convert::ToInt32(str));
}

Nullable<float> Row::ToNullableSingle(String^ str)
{
	if (str == "") return Nullable<float>();
	else return Nullable<float>(Convert::ToSingle(str));
}


void Row::parseLine(String^ rowLine) {
	array<String^>^ columns = rowLine->Split(';');
	if (columns->Length != COL_COUNT) { 
		throw gcnew Exception(L"Не правильный формат файла");
	}

	comp = columns[0];
	add = columns[1];
	post = columns[2];
	sal = ToNullableSingle(columns[3]);
	edu = columns[4];
	exp = ToNullableInt32(columns[5]);
	cond = columns[6];
}