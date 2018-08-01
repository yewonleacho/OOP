#include "std_lib_facilities.h"


class Token{
	public:
		char kind;
		double value;
};

Token get_token(); 

vector<Token> tokens;

int main(){
	Token t = get_token();
	while (t.kind != 'q'){
		tokens.push_back(t);
		t = get_token();
	}
	for (Token tok: tokens){    //If you are looping over the items in the vector, just use this form, not counting
		cout << "Token of kind: " << tok.kind << " with val " << tok.value << endl;
	}
}

Token get_token(){
	char ch;
	cin >> ch;
	switch(ch){
		case '+': case '-': case '*': case '/': case '(': case ')': case 'q': 
			return Token{ch}; 
		case'0': case'1': case'2': case'3': case'4': case'5': case'6': case'7': case'8': case'9': {
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{'8', val};
			}	
		}
	}

