#pragma once
using namespace System;

ref class SearchRow
{
public:
	property String^ cond;
	property String^ exp;
	property String^ edu;
	property String^ sal;
	property String^ post;
	property String^ add;
	property String^ comp;

	bool compareSal(Nullable<Decimal> v_sal);  //��������� ��������� ��� ������
	bool compareExp(Nullable<int> v_exp);  //��������� ����� ��� ������

};

