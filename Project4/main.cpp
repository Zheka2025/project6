#include"String.h"

String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	cout << typeid(typeid("Hello").name()).name() << endl;
	String str0;	//Default constructor
	str0.print();
	String str1 = "Hello";	//Single argument constructor
	cout << str1 << endl;
	String str2 = str1;	//Copy Constructor
	cout << str2 << endl;
	str0 = str1;	//Copy assignment
	cout << str0 << endl;
	cout << "\n---------------------------------\n";
	str2 = str2;
	cout << str2 << endl;
	cout << "\n---------------------------------\n";
#endif // CONSTRUCTORS_CHECK
	
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + " " + str2;
	cout << str3 << endl;
	cout << delimiter << endl;
}