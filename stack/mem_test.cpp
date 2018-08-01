#include "std_lib_facilities.h"

int main(){
	int i = 0;
	while (true){
		double* dptr = new double[10000];
		cout << "Loop " << i << endl;
		i++;
	}
}

//stopped after i = 170045
//tested on PythonAnywhere only
