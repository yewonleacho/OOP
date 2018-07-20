#include "std_lib_facilities.h"

//calculator version 1

class Token{
public:
	char kind;
	double value;
};

class Token_stream{
public:
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full{false};
	Token buffer;
};


void Token_stream::putback(Token t){
	buffer = t;
	full = true;
}

Token Token_stream::get(){
	if (full){
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch(ch){
		case';': case'q': case'(': case')': case'+': case'-': case'*': case'/': case'%':
			return Token{ch};
		case'.': case'1': case'2': case'3': case'4': case'5': case'6': case'7': case'8': case'9': case'0':{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{'8', val};
		}
		default:
			return Token{'i', double(ch)};
	}
	return Token{'q'};
}

void Token_stream::ignore(char c)
{
    //checking first buffer
    if(full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    //checking input
    char ch = 0;
    while(cin >> ch)
        if(ch == c) 
        	return;
}

Token_stream ts;
double expression(Token_stream& ts);


double primary(Token_stream& ts){
	Token t = ts.get();
	switch(t.kind){
		case '(':{
			//we will expect an expression, and then a ')'
			double d = expression(ts);
			t = ts.get();
			if (t.kind != ')')
				error("')' is expected");
			return d;
		}
		case'1': case'2': case'3': case'4': case'5': case'6': case'7': case'8': case'9': case'0':
			return t.value;
		case '+':
			return primary(ts);
		case '-':
			return -primary(ts);
		default:
			error("primary expected");
	}
	return 0.0;
}

double term(Token_stream& ts){
	double left = primary(ts);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			//we need a case to handle * and /
			case '*':{
				left *= primary(ts);
				t = ts.get();
				break;
			}
			case '/':{
				double d = primary(ts);
				if (d == 0)
					error("divide by 0");
				left /= d;
				t = ts.get();
				break;
			}
			//the default case will return left
			default:{
				ts.putback(t);
				return left;
			}
		}
	}
}

double expression(Token_stream& ts){
	double left = term(ts);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			//we need a case to handle + and -
			case '+':{
				left += term(ts);
				t = ts.get();
				break;
			}
			case '-':{
				left -= term(ts);
				t = ts.get();
				break;
			}
			//the default case will return left
			default:{
				ts.putback(t);
				return left;
			}
		}
	}
}

int main(){
		while (cin){
			try{
				Token t = ts.get();
				while (t.kind == ';')
					t = ts.get();
				if (t.kind == 'q')
					return 0;
				ts.putback(t);
				cout << " = " << expression(ts) << endl;
			}
			catch (exception& e){
				cerr << e.what() << endl;
				ts.ignore(';');
			}
		}
	}

	
