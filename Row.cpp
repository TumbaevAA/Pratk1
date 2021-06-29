#include "Row.h"

Row::Row() {
	_delimiter = '\t';
}

Row::Row(String^ rowLine) {
	if (rowLine != nullptr) {
		parseLine(rowLine);
	}
}

String^ Row::ToCsvString() {
	return String::Join("\t", gcnew array<String^>{comp, add, post, Convert::ToString(sal), Convert::ToString(edu), Convert::ToString(exp), Convert::ToString(cond)});
} 

void Row::parseLine(String^ rowLine) {
	array<String^>^ columns = rowLine->Split(_delimiter);
	if (columns->Length != COL_COUNT) {
		throw gcnew Exception(L"Не правильный формат файла");
	}

	comp = columns[0];
	add = columns[1];
	post = columns[2];
	sal = Convert::ToInt32(columns[3]);
	edu = Convert::ToInt32(columns[4]);
	exp = Convert::ToInt32(columns[5]);
	cond = Convert::ToInt32(columns[6]);
}