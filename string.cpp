#include <iostream>
#include <cstring>

using namespace std;

int main() {
/* Nhap chuoi*/
	//c style
	//char name[] = "Hieu Nguyen";//{'\0'};
	//C++
//	char full_name[50];
//
//	cout << "Enter your full name: ";
	//cin.getline(full_name, 50, '\n');
//	gets(full_name);
//	cout << "Your full name is " << full_name << endl;
	//	string myname;
//	cin.ignore();
//	cout << "Enter your name: ";
//
//	cin.getline(myname,20);
//
//	cout << "Hello " << myname << endl;
	//cstring.h in C++
	char foo[] = "Almost every programmer should know memset!";
	cout << foo << endl;
	cout << "Length of foo string: " << strlen(foo) << endl;
	memset(foo, '-', 7);
	cout << foo << endl;
	memset(foo, 'a', sizeof(foo));
	foo[sizeof(foo) - 1] = '\0'; 
	cout << foo << endl;
	
	char str_source[] = "This is source string";
	char str_destination[30];
	
	strcpy(str_destination, str_source);//copy
	cout << "str_destination: " << str_destination << endl;
	//compare
	char str1[] = "This is a string";
	char str2[] = "This is a string";
	
	if(strcmp(str1, str2) == 0)	{
		cout << "str1 and str2 are equal" << endl;		
	}
	else	{
		cout << "str1 ans str2 are not equal" << endl;
	}
	//thao tac strcat
	char str_destination2[50] = "Hello";
	strcat( str_destination2, " " );
	strcat( str_destination2, "every" );
	strcat( str_destination2, "one");
	
	cout << str_destination2 << endl;
	//tim kiem
	char text[] = "This is a simple string";
	char pattern[] = "simple";
	
	char *p = strstr(text, pattern);
	
	if (p == NULL) {
		cout << "Could not find the pattern string in the text string" << endl;
	}
	else    {
	
		int match_index = (p - text) / sizeof(char);///int32_t
		cout << "The pattern string match the text string at: " << match_index << endl;
	}
	return 0;
}
