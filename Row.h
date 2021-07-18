#pragma once
using namespace System;
using namespace System::Globalization;

const int COL_COUNT = 7; //Максимальное кол-во столбцов


ref class Row
{
public:
	Row();
	Row(String^ rowLine);
	String^ ToCsvString();      //Преобразование в csv
	bool parseLine(String^ rowLine, bool write); //Преобразование из csv

	Nullable<int> ToNullableInt32(String^ str);//Преобразование строки из файла в NullableInt32

	Nullable<Decimal> ToNullableDecimal(String^ str);//Преобразование строки из файла в NullableDecimal


	property String^ cond;
	property Nullable<int> exp;
	property String^ edu;
	property Nullable<Decimal> sal;
	property String^ post;
	property String^ add;
	property String^ comp;

};

