#include<iostream>
using namespace std;

/*
TODO:
Добавить в класс MoveConstructor и MoveAssignment, и проверить их работу.
http://www.cplusplus.com/doc/tutorial/classes2/
Перегрузить оператор +. DONE
*/

#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"

//#define CONSTRUCTOR_CHECK

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;   // Размер строки
	char* str; // Адрес строки в динамической памяти
public:
	int get_size() const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	String(int size = 80) : size(size == 0 ? 80 : size > 0 ? size : -size), str(new char[size] {})
	{
		/*this->size = size;
		this->str = new char[size] {};*/
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char str[]) :String(strlen(str) + 1)
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other) : size(other.size), str(new char[size] {})
	{
		/*this->size = other.size;
		this->str = new char[size] {};*/
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	String(String&& other) : size(other.size), str(other.str)
	{
		//this->size = other.size;
		//this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}


	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	String& operator+=(const String& other)
	{

		return *this = *this + other;
	}

	const char& operator[](int i) const

	{
		return this->str[i];
	}

	char& operator[](int i)
	{
		return this->str[i];
	}

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}

	void print()
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buffer = (left.get_size() + right.get_size() - 1);
	/*for (int i = 0; left.get_str()[i]; i++)
	buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; left.get_str()[i]; i++)
	buffer.get_str()[i + left.get_size()-1] = right.get_str()[i];*/
	for (int i = 0; left[i]; i++)
		buffer[i] = left[i];
	for (int i = 0; left[i]; i++)
		buffer[i + left.get_size() - 1] = right[i];
	return buffer;
}

void main()
{
	setlocale(0, "");
#ifdef CONSTRUCTOR_CHECK
	String str0;
	str0.print();
	cout << typeid("Hello").name() << endl;
	String str1 = "Hello";
	str1.print();
	cout << delimiter;
	cout << str1 << endl;
	cout << delimiter;
	String str2 = str1;
	cout << str2 << endl;
	cout << delimiter;
	str0 = str1;
	cout << str0 << endl;
	cout << delimiter;
	str2 = str2;
	cout << str2 << endl;
	cout << delimiter;
#endif CONSTRUCTOR_CHECK

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + " " + str2;
	cout << str3 << endl;
	cout << delimiter << endl;
	str1 = str1 + " " + str2;
	cout << str1 << endl;
	cout << delimiter << endl;
}