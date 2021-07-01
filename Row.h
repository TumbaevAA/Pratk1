#pragma once
using namespace System;
using namespace System::ComponentModel;

const int COL_COUNT = 7; //Максимаьлное кол-во столбцов


ref class Row
{
private:
	void parseLine(String^ rowLine);

public:
	Row();
	Row(String^ rowLine);
	String^ ToCsvString();

	Nullable<int> ToNullableInt32(String^ str);//Преобразование строки из файла в NullableInt32
	Nullable<float> ToNullableSingle(String^ str);//Преобразование строки из файла в NullableSingle

	property String^ cond;
	property Nullable<int> exp;
	property String^ edu;
	property Nullable<float> sal;
	property String^ post;
	property String^ add;
	property String^ comp;

};

