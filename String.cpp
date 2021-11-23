#pragma warning(disable : 4996) //что бы не использовать безопасные функции
#include "String.h"
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;



//Конструктор преобразования: Преобразует char* в String
String::String(const char* s)
{
	cout << "Conversion constructor: " << s << endl;
	length = strlen(s); //вчисление длины
	sPtr = new char[length + 1]; //выделение памяти
	assert(sPtr != 0); //выход если не выделена
	strcpy(sPtr, s); //скопировать строку в объект
}
// Конструктор копии
String::String(const String& copy)
{
	cout << "Copy constructor: " << copy.sPtr << endl;
	length = copy.length; //скопировать длину
	sPtr = new char[length + 1]; //выделить память
	assert(sPtr != 0);//проверить результат
	strcpy(sPtr, copy.sPtr); //скопировать строку
}
//деструктор
String::~String()
{
	cout << "Destructor: " << sPtr << endl;
	delete[] sPtr; //очистить строку
}
//Перегруженная операция =; избегать самоприсваивания
const String& String::operator=(const String& rigth)
{
	cout << "operators called" << endl;

	if (&rigth != this) //избегать самоприсваивания
	{
		delete[] sPtr; //предотвратить утечку памяти
		length = rigth.length; //новая длина строки
		sPtr = new char[length + 1]; //выделяем память
		assert(sPtr != 0); //проверка результата
		strcpy(sPtr, rigth.sPtr); //скопировать строку
	}
	else
		cout << "Attempted assigment of a String to itself \n";
	return *this; //разрешить конкатенацию присваиваний
}

//Конкатенация правого операнда с этим объектом
// и сохранение результата в этом объекте

String& String::operator+=(const String& right)
{
	char* tempPtr = sPtr; //сохранить, чтобы иметь возможность стереть
	length += right.length; //новая длина String
	sPtr = new char[length + 1]; //выделение памяти
	assert(sPtr != 0); //выйти если память не размещена
	strcpy(sPtr, tempPtr); // левая часть новой String
	strcat(sPtr, right.sPtr); //правая часть новой String
	delete[] tempPtr; // восстановить старое место 
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
	return strcmp(sPtr, rigth.sPtr) == 0;
}
//String не равна правой String?
int String::operator!=(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) != 0;
}
//String меньше чем правая String?
int String::operator<(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) < 0;
}
//String больше чем правая String?
int String::operator>(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) > 0;
}
//String больше или равна чем правая String?
int String::operator>=(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) >= 0;
}
//String меньше или равна чем правая String?
int String::operator<=(const String& rigth) const
{
	return strcmp(sPtr, rigth.sPtr) <= 0;
}
//Возврат ссылна на символ в String
char& String::operator[](int subscript)
{
	//проверка выход индекса за границы
	assert(subscript >= 0 && subscript < length);
	return sPtr[subscript]; //создать lvalue
}
//Возврат подстроки, начинающейся с index и
//длиной subLength как ссылки на объект String
String& String::operator()(int index, int subLength)
{
	//убедимся что индес находится в границах и длина подстроки >=0
	assert((index >= 0) && (index < length) && (subLength >= 0));
	String* subPtr = new String;//пустая String 
	assert(subPtr != 0); //проверка выделения памяти
	//определение длины подстроки
	int size;
	if ((subLength == 0) || (index + subLength > length))
		size = length - index + 1;
	else
		size = subLength + 1;
	//разместить память и подстроки
	delete subPtr->sPtr;
	subPtr->length = size;
	subPtr->sPtr = new char[size];
	assert(subPtr->sPtr != 0); //проверка выделения памяти
	//скопировать подстроку в новую String
	for (int i = index, j = 0; i < index + size - 1; i++, j++)
	{
		subPtr->sPtr[j] = sPtr[i];
		subPtr->sPtr[j] = '\0'; //ограничить новую строку нулевым символом
	}

	return *subPtr;
}

//Возврат длины строки
int String::getLength() const
{
	return length;
}

//Перегруженная операция вывода 
ostream& operator<< (ostream& output, const String& string)
{
	output << string.sPtr; 
	return output; //разрешить конкатенацию
}

//Перегруженная операция ввода
istream& operator>> (istream& input, String& s)
{
	static char temp[100]; //буфеер ввода
	input >> temp;
	s = temp; // используем операцию присвааивания класса String
	return input; //разрешить конкатенацию
}