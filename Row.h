#pragma once
using namespace System;
using namespace System::ComponentModel;

const int COL_COUNT = 7; //������������ ���-�� ��������


ref class Row
{
private:
	void parseLine(String^ rowLine);
	char _delimiter;                   //�����������


public:
	Row();
	Row(String^ rowLine);
	String^ ToCsvString();


	[DisplayName("���. �������")]
	property Nullable<int> cond;
	[DisplayName("����")]
	property Nullable<int> exp;
	[DisplayName("�����������")]
	property Nullable<int> edu;
	[DisplayName("��������")]
	property Nullable<int> sal;
	[DisplayName("���������")]
	property String^ post;
	[DisplayName("�����")]
	property String^ add;
	[DisplayName ("�����������")] 
	property String^ comp;

};

