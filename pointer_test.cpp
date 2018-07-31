#include "std_lib_facilities.h"

int main(){
	char c = 'a';
	int i = 4092;
	double d = 3.14;
	char* cp = &c;
	int* ip = &i;
	double* dp = &d;
	cout << "cp = " << cp << " and its value is " << *cp << endl;
	cout << "Size of cp is " << sizeof(cp) << " and size of c is " << sizeof(c) << endl;
	cout << "ip = " << ip << " and its value is " << *ip << endl;
	cout << "Size of ip is " << sizeof(ip) << " and size of i is " << sizeof(i) << endl;
	cout << "dp = " << dp << " and its value is " << *dp << endl;
	cout<< "Size of dp is " << sizeof(dp) << " and its size of d is " << sizeof(d) << endl;
}

/*cp = a and its value is a
Size of cp is 8 and size of c is 1
ip = 0x7ffdb702119c and its value is 4092
Size of ip is 8 and size of i is 4
dp = 0x7ffdb70211a0 and its value is 3.14
Size of dp is 8 and its size of d is 8 */


