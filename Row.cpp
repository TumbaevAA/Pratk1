#include "Row.h"

Row::Row() {
	
}

Row::Row(String^ rowLine) {
	if (rowLine != nullptr) {
		parseLine(rowLine, true);
	}
}


//Преобразование в csv
String^ Row::ToCsvString() {
	return String::Join(";", gcnew array<String^>{comp, add, post, Convert::ToString(sal, CultureInfo::InstalledUICulture), edu, Convert::ToString(exp, CultureInfo::InvariantCulture), cond}) + "\n";
}

//Преобразование в Nullable Int32
Nullable<int> Row::ToNullableInt32(String^ str)
{
	int value;
	if (int::TryParse(str, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite, CultureInfo::InvariantCulture, value)) 
		return Nullable<int>(value);
	else return Nullable<int>();
}

//Преобразование в Nullacle Decimal
Nullable<Decimal> Row::ToNullableDecimal(String^ str)
{
	Decimal value;
	if (Decimal::TryParse(str, NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowDecimalPoint, CultureInfo::InstalledUICulture, value))
		return Nullable<Decimal>(value);
	else return Nullable<Decimal>();
}


//Преобразование из csv
bool Row::parseLine(String^ rowLine, bool write) {

	
	array<String^>^ columns = rowLine->Split(';');
	if (write == false && columns->Length != COL_COUNT) //Если нужно только проверить файл, то write == false
		return false;
	

	else
	{
		comp = columns[0];
		add = columns[1];
		post = columns[2];
		sal = ToNullableDecimal(columns[3]);
		edu = columns[4];
		exp = ToNullableInt32(columns[5]);
		cond = columns[6];
	}
	
	return true;
}