/*CS-2124 HW1
Yewon Cho
Unsafe Type Conversion

Write a program that tests all of the unsafe type conversions listed above. 
For instance, initialize a double, assign it to an int, 
and then print out the initial value you used and the resulting value in the "narrowed" type. 
Convert back to the broader type, and output that va`lue, so you can see what was lost.
*/

#include "std_lib_facilities.h"

int main(){
    //double to int
    double a = 4.49;
    int b = a;
    double c = b;
    cout << "double a: " << a << endl;
    cout << "int b: " << b << endl;
    cout << "double c: " << c << endl;
    cout << "\n";
    
    //double to char
    double d = 6.2;
    //char e[5] = {static_cast<char>(d)};
    //double f = e;
    cout << "double d: " << d << endl;
    //cout << "char e: " << e << endl;
    //cout << "double f: " << f << endl;
    cout << "\n";
    
    //double to bool
    double g = 0.0;
    bool h = g;
    double i = h;
    cout << "double g: " << g << endl;
    cout << "bool h: " << h << endl;
    cout << "double i: " << i << endl;
    cout << "\n";
    
    //int to char
    int j = 5;
    char k = j;
    int l = k;
    cout << "int j: " << j << endl;
    cout << "char k: " << k << endl;
    cout << "int l: " << l << endl;
    cout << "\n";
    
    //int to bool
    int m = 1;
    bool n = m;
    int o = n;
    cout << "int m: " << m << endl;
    cout << "bool n: " << n << endl;
    cout << "int o: " << o << endl;
    cout << "\n";
    
    //char to bool
    char p = '1';
    bool q = p;
    char r = q;
    cout << "char p: " << p << endl;
    cout << "bool q: " << q << endl;
    cout << "char r: " << r << endl;
}
