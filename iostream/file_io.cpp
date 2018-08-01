#include "std_lib_facilities.h"

struct Reading{
	int temp1;
	char comma1;
	double temp2;
	char comma2;
	double temp3;
};

int main(){
	cout << "Please enter the name of the input file: ";
	string iname;
	cin >> iname;
	ifstream ist{iname};
	if (!ist) error("Can't open the input file ", iname);

	cout << "Please enter the name of the output file: ";
	string oname;
	cin >> oname;
	ofstream ost{oname};
	if (!ost) error("Can't open the output file ", oname);

	vector<Reading> temps;
	int temp1;
	char comma1, comma2;
	double temp2, temp3;
	while (ist >> temp1 >> comma1 >> temp2 >> comma2 >> temp3){
		if (temp1 < 0 || temp1 > 23) error("Temp1 is out of range.");
		temps.push_back(Reading{temp1, comma1, temp2, comma2, temp3});
	}
	for (int i = 0; i < temps.size(); ++i)
		ost << temps[i].temp1 << '\t' << temps[i].temp2 << '\t' << temps[i].temp3 << endl;
}