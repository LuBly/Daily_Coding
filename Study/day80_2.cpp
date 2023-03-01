//[BaekJoon C++] 서로 다른 부분 문자열의 개수 [집합과 맵]
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string input;
    cin>>input;
    set<string> answer;
    for(int start=0;start<input.size();start++){
        for(int size=1;size<input.size()-start+1;size++){
            answer.insert(input.substr(start,size));
        }
    }
    cout<<answer.size();
}