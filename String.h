#pragma once



#include <iostream>
#include <vector>
using namespace std;

class String
{
	friend ostream& operator<< (ostream&, const String&);
	friend istream& operator>> (istream&, String&);

public:
	String(const vector<char> ); //конструктор преобразования
	String(const String&); //конструкор копии
	String(const char* );
	~String(); //деструктор
	const String& operator=(const String&); //присваивание
	String& operator+=(const String&);//конкатенация
	int operator!() const; //String пустая?
	int operator==(const String&) const; //проверка s1==s2
	int operator!=(const String&) const; //проверка s1!=s2
	int operator<(const String&) const; //проверка s1>s2
	int operator>(const String&) const;//проверка s1<s2
	int operator>=(const String&) const; //проверка s1>=s2
	int operator<=(const String&) const; //проверка s1<=s2
	char& operator[](int); //возврат ссылки char
	//char* sPtr;//указатель на начало строки
	String& operator()(int, int);//возврат подстроки
	int getLength() const; //возврат длины строки

private:
	vector<char> sPtr;
//	int length; //длина строки
};

 //  STRING1_H



