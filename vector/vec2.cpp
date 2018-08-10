#include "std_lib_facilities.h"

class vect{
	int size;
	double* elem;

public:
	vect(int s)
	: size{s}, elem{new double [s]}{};

	~vect(){delete[] elem;}

	vect(const vect& arg)
	: size(arg.size), elem{new double[arg.size]}{
		copy(arg.elem, arg.elem + arg.size, elem);
	}

	vect& operator=(const vect& arg){
		double* p = new double[arg.size];
		copy(arg.elem, arg.elem + arg.size, p);
		delete[] elem;
		elem = p;
		size = arg.size;
		return *this;
	}

	double operator[](int n){return elem[n];};
	double get(int i){return elem[i];};
	void set(int i, double d){elem[i] = d;};
};

void f(int n){
	vect v(3);
	v.set(2, 2.2);
	vect v2 = v;
	v.set(1, 9.9);
	v2.set(0, 8.8);
	cout << v.get(0) << " " << v2.get(1) << endl;
}

int main(){
	for (int i = 0; i < 10000; i++)
		f(i);
	return 0;
}