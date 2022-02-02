#pragma warning(disable : 4996) //что бы не использовать безопасные функции
#include "String.h"
#include <iostream>
#include <string.h>
using namespace std;

String::String(const vector<char> s)
{	
	//cout << "Conversion constructor: ";
	for (int i=0;i<s.size();i++)
		cout << s[i];
	length = s.size(); //вчисление длины
	//vector<char> sPtr(0, length); //выделение памяти
	sPtr = s;
}
// Конструктор копии
String::String(const String& copy)
{
	cout << "Copy constructor: ";
	for (auto element : copy.sPtr)
		cout << element;
	cout << endl;
	length = copy.length; 
	vector<char> sPtr(0, length);
	sPtr = copy.sPtr;
}
String::String(const char* test)
{
	vector<char> charstr;	
	int len = strlen(test);
	// Выводим символы в прямом порядке
	for (int i = 0; i < len; ++i) {
		charstr.push_back(test[i]);
	}
	sPtr = charstr;
}
//деструктор
String::~String()
{
	cout << "Destructor: ";
	for (auto element : sPtr)
		cout << element;
	cout << endl;
	sPtr.clear(); //очистить строку
}
//Перегруженная операция =; избегать самоприсваивания
const String& String::operator=(const String& rigth)
{
	cout << "operators called" << endl;

	if (&rigth != this) //избегать самоприсваивания
	{
		sPtr = rigth.sPtr;
	}
	else
		cout << "Attempted assigment of a String to itself \n";
	return *this; //разрешить конкатенацию присваиваний
}

//Конкатенация правого операнда с этим объектом
// и сохранение результата в этом объекте

String& String::operator+=(const String& right)
{
	vector<char> tempPtr = sPtr; //сохранить, чтобы иметь возможность стереть
	length += right.length; //новая длина String
	sPtr.reserve(length + 1); //выделение памяти
	//assert(sPtr != 0); //выйти если память не размещена
	tempPtr = sPtr; // левая часть новой String
	for (int i = 0; i < right.sPtr.size(); i++)
	{
		sPtr.push_back(right.sPtr[i]);
	}
	tempPtr.clear(); // восстановить старое место 
	return *this; // рзарешить конкатенацию вызовов
}
//String пустая?
int String::operator!() const 
{
	return length == 0;
}
//String равна правой String?
int String::operator==(const String& rigth) const
{
	if (sPtr == rigth.sPtr)
		return true;
}
//String не равна правой String?
int String::operator!=(const String& rigth) const
{
	if (sPtr != rigth.sPtr)
		return true;

}
//String меньше чем правая String?
int String::operator<(const String& rigth) const
{
	if (sPtr.size() < rigth.sPtr.size())
		return true;

}
//String больше чем правая String?
int String::operator>(const String& rigth) const
{
	if (sPtr.size() > rigth.sPtr.size())
		return true;

}
//String больше или равна чем правая String?
int String::operator>=(const String& rigth) const
{
	if (sPtr.size() >= rigth.sPtr.size())
		return true;

}
//String меньше или равна чем правая String?
int String::operator<=(const String& rigth) const
{
	if (sPtr.size() <= rigth.sPtr.size())
		return true;

}
//Возврат ссылна на символ в String
char& String::operator[](int subscript)
{

	return sPtr[subscript]; //создать lvalue
}

String& String::operator()(int index, int subLength)
{

	if ((index >= 0) && (index < length) && (subLength >= 0))
	{
	
		int size;
		if ((subLength == 0) || (index + subLength > length))
			size = length - index + 1;
		else
			size = subLength + 1;
		vector<char> newSubStr(0, size);
		for (int i = index; i < subLength; i++)
		{
			newSubStr.push_back(sPtr.at(i));
		}
		String* subPtr = new String(newSubStr);
		return *subPtr;
	}
	else
		cout << "Fatal exception!";
	
}

//Возврат длины строки
int String::getLength() const
{
	return length;
}

//Перегруженная операция вывода 
ostream& operator<< (ostream& output, const String& string)
{
	for (int i=0; i<string.length;i++)
		output << string.sPtr[i]; 
	return output; //разрешить конкатенацию
}

//Перегруженная операция ввода
istream& operator>> (istream& input, String& s)
{
	static char temp[100]; //буфеер ввода
	input >> temp;
	vector<char> data(temp, temp + 1);
	s = data; // используем операцию присвааивания класса String
	return input; //разрешить конкатенацию
}