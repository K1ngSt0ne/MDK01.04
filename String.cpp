#pragma warning(disable : 4996) //��� �� �� ������������ ���������� �������
#include "String.h"
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;



//����������� ��������������: ����������� char* � String
String::String(const char* s)
{
	cout << "Conversion constructor: " << s << endl;
	length = strlen(s); //��������� �����
	sPtr = new char[length + 1]; //��������� ������
	assert(sPtr != 0); //����� ���� �� ��������
	strcpy(sPtr, s); //����������� ������ � ������
}
// ����������� �����
String::String(const String& copy)
{
	cout << "Copy constructor: " << copy.sPtr << endl;
	length = copy.length; //����������� �����
	sPtr = new char[length + 1]; //�������� ������
	assert(sPtr != 0);//��������� ���������
	strcpy(sPtr, copy.sPtr); //����������� ������
}
//����������
String::~String()
{
	cout << "Destructor: " << sPtr << endl;
	delete[] sPtr; //�������� ������
}
//������������� �������� =; �������� ����������������
const String& String::operator=(const String& rigth)
{
	cout << "operators called" << endl;

	if (&rigth != this) //�������� ����������������
	{
		delete[] sPtr; //������������� ������ ������
		length = rigth.length; //����� ����� ������
		sPtr = new char[length + 1]; //�������� ������
		assert(sPtr != 0); //�������� ����������
		strcpy(sPtr, rigth.sPtr); //����������� ������
	}
	else
		cout << "Attempted assigment of a String to itself \n";
	return *this; //��������� ������������ ������������
}

//������������ ������� �������� � ���� ��������
// � ���������� ���������� � ���� �������

String& String::operator+=(const String& right)
{
	char* tempPtr = sPtr; //���������, ����� ����� ����������� �������
	length += right.length; //����� ����� String
	sPtr = new char[length + 1]; //��������� ������
	assert(sPtr != 0); //����� ���� ������ �� ���������
	strcpy(sPtr, tempPtr); // ����� ����� ����� String
	strcat(sPtr, right.sPtr); //������ ����� ����� String
	delete[] tempPtr; // ������������ ������ ����� 
	return *this; // ��������� ������������ �������
}
//String ������?
int String::operator!() const 
{
	return length == 0;
}
//String ����� ������ String?
int String::operator==(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) == 0;
}
//String �� ����� ������ String?
int String::operator!=(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) != 0;
}
//String ������ ��� ������ String?
int String::operator<(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) < 0;
}
//String ������ ��� ������ String?
int String::operator>(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) > 0;
}
//String ������ ��� ����� ��� ������ String?
int String::operator>=(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) >= 0;
}
//String ������ ��� ����� ��� ������ String?
int String::operator<=(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) <= 0;
}
//������� ������ �� ������ � String
char& String::operator[](int subscript)
{
	//�������� ����� ������� �� �������
	assert(subscript >= 0 && subscript < length);
	return sPtr[subscript]; //������� lvalue
}
//������� ���������, ������������ � index �
//������ subLength ��� ������ �� ������ String
String& String::operator()(int index, int subLength)
{
	//�������� ��� ����� ��������� � �������� � ����� ��������� >=0
	assert((index >= 0) && (index < length) && (subLength >= 0));
	String* subPtr = new String;//������ String 
	assert(subPtr != 0); //�������� ��������� ������
	//����������� ����� ���������
	int size;
	if ((subLength == 0) || (index + subLength > length))
		size = length - index + 1;
	else
		size = subLength + 1;
	//���������� ������ � ���������
	delete subPtr->sPtr;
	subPtr->length = size;
	subPtr->sPtr = new char[size];
	assert(subPtr->sPtr != 0); //�������� ��������� ������
	//����������� ��������� � ����� String
	for (int i = index, j = 0; i < index + size - 1; i++, j++)
	{
		subPtr->sPtr[j] = sPtr[i];
		subPtr->sPtr[j] = '\0'; //���������� ����� ������ ������� ��������
	}

	return *subPtr;
}

//������� ����� ������
int String::getLength() const
{
	return length;
}

//������������� �������� ������ 
ostream& operator<< (ostream& output, const String& string)
{
	output << string.sPtr; 
	return output; //��������� ������������
}

//������������� �������� �����
istream& operator>> (istream& input, String& s)
{
	static char temp[100]; //������ �����
	input >> temp;
	s = temp; // ���������� �������� ������������� ������ String
	return input; //��������� ������������
}