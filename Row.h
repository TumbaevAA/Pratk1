#pragma once
using namespace System;
using namespace System::ComponentModel;

const int COL_COUNT = 7; //Максимаьлное кол-во столбцов


ref class Row
{
private:
	void parseLine(String^ rowLine);
	char _delimiter;                   //Разделитель


public:
	Row();
	Row(String^ rowLine);
	String^ ToCsvString();


	[DisplayName("Жил. условия")]
	property Nullable<int> cond;
	[DisplayName("Стаж")]
	property Nullable<int> exp;
	[DisplayName("Образование")]
	property Nullable<int> edu;
	[DisplayName("Зарплата")]
	property Nullable<int> sal;
	[DisplayName("Должность")]
	property String^ post;
	[DisplayName("Адрес")]
	property String^ add;
	[DisplayName ("Предприятие")] 
	property String^ comp;

};

