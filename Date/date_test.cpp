#include "std_lib_facilities.h"
#include "date.h"


int main(){
	cout << "Please enter a date in format(YYYY,MM,DD): ";
	Date date1;
	cin >> date1;
	if (date1.isvalid() == false) throw Invalid{};
	date1.print_long();
}

