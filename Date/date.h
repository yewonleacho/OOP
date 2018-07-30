#include "std_lib_facilities.h"

enum class Month{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
}; //if we don't initialize the first enumerator, the count automatically starts with 0.


class Invalid{};

class Date{
public:
	Date(int y, Month m, int d); //constructor: check for valid date and initialize
	void add_day(int n);   //increase the Date by n days
	int year(); 
	int month();		
	int day();
	bool isvalid();
	bool leapyear();
	void print_long();
private:
	int y;
	Month m;
	int d;
};

vector<int> last_day{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> leap_last_day{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> month_name{"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
