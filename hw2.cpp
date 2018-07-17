#include "std_lib_facilities.h"
int main(){
    cout << "Enter the words: ";
    vector<string> text;
    
    for(string word; cin >> word;)
        text.push_back(word);
    sort(text);
    
    int cnt = 0;
    string prev = text[0];
    
    for(int i = 0; i < text.size(); i++){
        if (prev == text[i])
            cnt++;
        else{
            cout << prev << ": " << cnt << endl;
            cnt = 1;
            prev = text[i];
        }
    }
    cout << prev << ": " << cnt << endl;
    return 0;
}
