#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"
#include "funcs.h"

const string prompt = " >> ";
const string result = " = ";

double statement(Token_stream&s);
double expression(Token_stream&s);
double term(Token_stream&s);
double expon(Token_stream&s);
double primary(Token_stream&s);
void clean_up_mess(Token_stream&s);
void calculate(Token_stream&s);

double statement(Token_stream& ts){
	Token t = ts.get();
	if (t.kind == name){
		Token var = t;
		t = ts.get();
		if (t.kind == '='){
			double d = expression(ts);
			set_value(var.name, d);
			return d;
		}
		else if (t.kind == print){
			ts.putback(t);
			return get_value(var.name);
		}
		ts.putback(t);
		ts.putback(var);
		return expression(ts);
	}
	ts.putback(t);
	return expression(ts);
}

double expression(Token_stream& ts){
	double left = term(ts);
	Token t = ts.get();

	while (true) {
		switch(t.kind){
			case '+': 
				left += term(ts);
				t = ts.get();
				break;
			case '-':
				left -= term(ts);
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double term(Token_stream& ts){
	double left = expon(ts);
	Token t = ts.get();

	while (true){
		switch(t.kind){
			case '*': 
				left *= expon(ts);
				t = ts.get();
				break;
			case '/':{
				double d = expon(ts);
				if (d == 0) error("divided by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':{
				double d = expon(ts);
				if (d == 0) error("divdied by zero");
				left = fmod(left, d);
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expon(Token_stream& ts){
	double left = primary(ts);
	Token t = ts.get();
	if (t.kind == power){
		double d = primary(ts);
		return pow(left, d);
	}
	else {
		ts.putback(t);
		return left;
	}
}

double primary(Token_stream& ts){
	Token t = ts.get();
	switch(t.kind){
		case '(':{
			double d = expression(ts);
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case number:
			return t.value;
		case name:{
			Token next_t = ts.get();
			if (next_t.kind == '('){
				double d = expression(ts);
				d = exec_func(t.name, d);
				t = ts.get();
				if (t.kind != ')') error("')' expected ");
				return d;
			}
			else{
				ts.putback(next_t);
				return get_value(t.name);
			}
		}	
		case '+':
			return primary(ts);
		case '-':
			return -primary(ts);
		default:
			error("Primary expected");
	}
	return 0.0;
}


void clean_up_mess(Token_stream& ts){
	while (true){
		Token t = ts.get();
		if (t.kind == print) return;
	}
}

void calculate(Token_stream& ts){
	while (cin) {
		try{
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << setprecision(12) << result << statement(ts) << endl;
		}
		catch(exception& e){
			cerr << e.what() << endl;
			clean_up_mess(ts);
		}
	}
}


int main(){
	Token_stream ts;

	cout << "Please enter the expression: " << endl;

	try{
		calculate(ts);
		return 0;
	}
	catch(...){
		cerr << "Exception occurred \n";
		return 2;
	}
}
