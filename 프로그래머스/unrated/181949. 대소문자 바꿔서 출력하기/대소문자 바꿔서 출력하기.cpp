#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(int k=0;k<str.size();k++){
        if(isupper(str[k])) str[k]+=32;
        else str[k]-=32;
    }
    cout<<str;
    return 0;
}