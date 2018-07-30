#include "std_lib_facilities.h"
#include "date.h"
#include <iostream>

Date::date(int yy, Month mm, int dd): //constructor
	y{yy}, m{mm}, d{dd}{ 
		if (!is_valid()) throw Invalid{};
	}

void Date::add_day(int n){
	//...
}

int Date::year(){
	return y;
}

Month Date::month(){	
	return m;
}

int Date::day(){
	return d;
}

bool Date::leapyear(Date& d){
	if (d.year() % 4 == 0) return true;
	return false;
}

bool Date::isvalid(){
	if (int y < 1) return false;
	if (Month m < 1 || Month m > 12) return false;
	if (int d < 1) return false;
	if (Date::leapyear(int y) == true){
		if (int d > leap_last_day[m]) return false;
	}
	else if (int d > last_day[m]) return false;
	return true;
}

void print_long(Date& d){
	cout << month_name[int(m)] << " " << d.day() << ", " << d.year();
}

Month operator++(Month& m){
	m = (m == dec) ? jan : Month(int(m) + 1);
	return m;
}

ostream& operator<<(ostream& os, const Date& d){ 	//output operator overloading
  	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
  }

istream& operator>>(istream& is, Date& dd){		//input operator overloading
	int y, m, d;
	char ch1, ch2, ch3, ch4;
	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
	if (!is) return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')'){
		is.clear(ios_base::failbit);
		return is;
	}
	dd = Date{y, Date::Month(m), d};
	return is;
}
                
