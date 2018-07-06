#include "std_lib_facilities.h"

int main(){
	string first_name;
	cout << "Enter the name of the person you want to write to: \n";
	cin >> first_name;
	string friend_name;
	cout << "Enter the name of your friend: \n";
	cin >> friend_name;
	cout << "Enter the age: \n";
	int age;
	cin >> age;
	if (age < 0 || age > 110)
		simple_error("Please enter valid number.\n");
	else if (age < 17)
		cout << "You are young to be at NYU!\n";
	else if (age > 65)
		cout << "It's great to see senior students around campus!\n";

	cout << "Dear " << first_name << ", \n I am writing this letter to ask you something. ";
	cout << "Have you seen " << friend_name << " lately? ";
	cout << "I hear you had a birthday and you are now " << age << " years old!\n";
}