//[BaekJoon C++] 암호 만들기 [브루트포스]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> words;
int length, wordCnt;

bool isValid(string data){
    int vowelCnt = 0;
    for(int k = 0; k < length; k++){
        if(data[k] == 'a' || data[k] == 'e' || data[k] == 'i' || data[k] == 'o' || data[k] == 'u') vowelCnt++;
    }

    if(vowelCnt >= 1 && length - vowelCnt >= 2) return true;
    else return false;
}

void MakePassword(int idx, string data){
    if(data.size() == length){
        if(isValid(data)){
            cout << data << '\n';
            return;
        }
    }

    for(int k = idx; k < wordCnt; k++){
        MakePassword(k+1, data + words[k]);
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> length >> wordCnt;
    words.resize(wordCnt);
    
    for(int k = 0; k < wordCnt; k++){
        cin >> words[k];
    }
    sort(words.begin(), words.end());
    MakePassword(0, "");

}    