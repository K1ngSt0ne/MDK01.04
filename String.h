#pragma once

#ifndef STRING1_H
#define STRING1_H

#include <iostream>
using namespace std;

class String
{
	friend ostream& operator<< (ostream&, const String&);
	friend istream& operator>> (istream&, String&);

public:
	String(const char* = ""); //����������� ��������������
	String(const String&); //���������� �����
	~String(); //����������
	const String& operator=(const String&); //������������
	String& operator+=(const String&);//������������
	int operator!() const; //String ������?
	int operator==(const String&) const; //�������� s1==s2
	int operator!=(const String&) const; //�������� s1!=s2
	int operator<(const String&) const; //�������� s1>s2
	int operator>(const String&) const;//�������� s1<s2
	int operator>=(const String&) const; //�������� s1>=s2
	int operator<=(const String&) const; //�������� s1<=s2
	char& operator[](int); //������� ������ char
	char* sPtr;//��������� �� ������ ������
	String& operator()(int, int);//������� ���������
	int getLength() const; //������� ����� ������

private:
	
	int length; //����� ������
};

#endif //  STRING1_H



