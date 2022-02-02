/*Задание:
15.	Создайте класс String, который хранит строку текста.
Реализовать операции удаления подстроки по индексам первого/последнего
удаляемого символа, вставки символов, получения длины строки,
конкатенации другой строки.*/


#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	const char* test = "test";	
	const char* test2 = " you make";
	const char* test3 = " pro gress ";
	String s1(test), s2(test2), s3(test3);
	//проверка перегруженных операций равенства и отношений
	cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2 << "\"; s3 is empty\n"
		<< "The results of comparing s2 and s1: " 
		<< "\ns2 == s1 yields " << (s2 == s1)
		<< "\ns2 != s1 yields " << (s2 != s1)
		<< "\ns2 > s1 yields " << (s2 > s1)
		<< "\ns2 < s1 yields " << (s2 < s1)
		<< "\ns2 >= s1 yields " << (s2 >= s1)
		<< "\ns2 <= s1 yields " << (s2 <= s1) << "\n\n";

	//проверка содержимого String перегруженной операцией (!)
	cout << "Testing !s3:\n";
	if (!s3) {
		cout << "s3 is empty; assigning s1 to s3;\n";
		s3 = s1; //проверка перегруженной операции присваивания
		cout << "s3 is \"" << s3 << "\"\n\n";
	}

	//проверка перегруженной операции конкатенации String
	cout << "s1 += s2 yields s1 = ";
	s1 += s2; //проверка перегруженной конкатенации
	cout << s1 << "\n\n";

	//проверка перегруженного конструктора
	cout << "s1 += \" to you\" yields\n";
	s1 += " to you"; //проверка перегруженного конструктора
	cout << "s1 " << s1 << "\n\n";

	//проверка подстроки перегруженной функцией-
	//операцией вызова ()
	cout<< "The substring of s1 starting at\n" 
		<< "location 0 for 14 characters, s1 (0,14) is: " 
		<< s1(0,14) << "\n\n";
	//проверка опции подстроки (до конца строки)
	cout << "The substring of s1 starting at\n"
		<< "location 15, s1(15,0), is: "
		<< s1(15, 0) << "\n\n"; // 0 означает что "до конца строки"

	// проверка конструктора копии
	String* s4Ptr = new String(s1);
	cout << "*s4Ptr = " << *s4Ptr << "\n\n";

	//проверка операцаии присваивания (=) с самоприсваиванием
	cout << "assigning *s4Ptr to *s4Ptr\n";
	*s4Ptr = *s4Ptr; // проверка перегруженного самопррисваивания
	cout << "*s4Ptr = " << *s4Ptr << endl;

	//проверка деструктора
	delete s4Ptr;

	//проверка операции индексирования, возвращающей lvalue
	s1[0] = 'H';
	s1[6] = 'B';
	cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: " << s1 << "\n\n";

	//проверка на выход из границ
	cout << "Attemp to assign 'd' to s1[30] yields: \n";
	s1[30] = 'd'; // Ошибка! индекс вышел за границы массива

	return 0;
}
