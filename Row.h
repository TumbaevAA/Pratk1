#pragma once
using namespace System;
using namespace System::Globalization;

const int COL_COUNT = 7; //������������ ���-�� ��������


ref class Row
{
public:
	Row();
	Row(String^ rowLine);
	String^ ToCsvString();      //�������������� � csv
	bool parseLine(String^ rowLine, bool write); //�������������� �� csv

	Nullable<int> ToNullableInt32(String^ str);//�������������� ������ �� ����� � NullableInt32

	Nullable<Decimal> ToNullableDecimal(String^ str);//�������������� ������ �� ����� � NullableDecimal


	property String^ cond;
	property Nullable<int> exp;
	property String^ edu;
	property Nullable<Decimal> sal;
	property String^ post;
	property String^ add;
	property String^ comp;

};

