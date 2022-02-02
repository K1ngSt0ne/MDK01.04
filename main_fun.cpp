/*�������:
15.	�������� ����� String, ������� ������ ������ ������.
����������� �������� �������� ��������� �� �������� �������/����������
���������� �������, ������� ��������, ��������� ����� ������,
������������ ������ ������.*/


#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	const char* test = "happy";	
	const char* test2 = " birthday";
	const char* test3 = "";
	String s1(test), s2(test2), s3(test3);
	//�������� ������������� �������� ��������� � ���������
	cout << "s1 is " << s1;
	cout << "s2 is " << s2;
	cout << "s3 is " << s3
		<< "The results of comparing s2 and s1: " 
		<< "\ns2 == s1 yields " << (s2 == s1)
		<< "\ns2 != s1 yields " << (s2 != s1)
		<< "\ns2 > s1 yields " << (s2 > s1)
		<< "\ns2 < s1 yields " << (s2 < s1)
		<< "\ns2 >= s1 yields " << (s2 >= s1)
		<< "\ns2 <= s1 yields " << (s2 <= s1) << "\n\n";

	//�������� ����������� String ������������� ��������� (!)
	cout << "Testing !s3:\n";
	if (!s3) {
		cout << "s3 is empty; assigning s1 to s3;\n";
		s3 = s1; //�������� ������������� �������� ������������
		cout << "s3 is \"" << s3 << "\"\n\n";
	}

	//�������� ������������� �������� ������������ String
	cout << "s1 += s2 yields s1 = ";
	s1 += s2; //�������� ������������� ������������
	cout << s1 << "\n\n";

	//�������� �������������� ������������
	cout << "s1 += \" to you\" yields\n";
	s1 += " to you"; //�������� �������������� ������������
	cout << "s1 " << s1 << "\n\n";

	//�������� ��������� ������������� ��������-
	//��������� ������ ()
	cout<< "The substring of s1 starting at\n" 
		<< "location 0 for 14 characters, s1 (0,14) is: " 
		<< s1(0,3) << "\n\n";
	//�������� ����� ��������� (�� ����� ������)
	cout << "The substring of s1 starting at\n"
		<< "location 15, s1(15,0), is: "
		<< s1(15, 0) << "\n\n"; // 0 �������� ��� "�� ����� ������"

	// �������� ������������ �����
	String s4Ptr = s1;
	cout << "s4Ptr = " << s4Ptr << "\n\n";


	

	//�������� �������� ��������������, ������������ lvalue
	s1[0] = 'H';
	s1[6] = 'B';
	cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: " << s1 << "\n\n";

	//�������� �� ����� �� ������
	cout << "Attemp to assign 'd' to s1[30] yields: \n";
	s1[30] = 'd'; // ������! ������ ����� �� ������� �������

	return 0;
}
