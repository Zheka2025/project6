#pragma
#include<iostream>
using namespace std;
using std::cout;

#define delimiter "\n------------------------------\n"

/*
	TODO:
	Добавить в класс MoveConstructor и MoveAssignment, и проверить их работу.
	http://www.cplusplus.com/doc/tutorial/classes2/
	Перегрузить оператор +. DONE
*/

//#define CONSTRUCTORS_CHECK

class String
{
	int size;	//Размер строки
	char* str;	//Адрес строки в динамической памяти
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