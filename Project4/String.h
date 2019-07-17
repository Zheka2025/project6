#pragma
#include<iostream>
using namespace std;
using std::cout;

#define delimiter "\n------------------------------\n"

/*
	TODO:
	�������� � ����� MoveConstructor � MoveAssignment, � ��������� �� ������.
	http://www.cplusplus.com/doc/tutorial/classes2/
	����������� �������� +. DONE
*/

//#define CONSTRUCTORS_CHECK

class String
{
	int size;	//������ ������
	char* str;	//����� ������ � ������������ ������
public:
	int get_size() const;
	const char* get_str() const;
	char* get_str();
	//			Constructors:
	String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);
	//			Methods
	void print();
};