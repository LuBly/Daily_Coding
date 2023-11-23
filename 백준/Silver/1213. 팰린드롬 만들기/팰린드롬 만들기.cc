//[Baekjoon C++] 팰린드롬 만들기 [그리디]
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string input;
    cin >> input;

    int length = input.size();
    map<char,int> mp;
    for(int k = 0; k < length; k++){
        mp[input[k]]++;
    }

    vector<char> output(length);

    int oddCnt = 0;
    char oddChar;
    for(auto iter : mp){
        if(iter.second % 2 != 0){
            oddCnt++;
            oddChar = iter.first;    
        }
    }

    if(oddCnt > 1){
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    int idx = 0;
    string answer = "";
    string reverseAnswer = "";
    string temp;
    if(oddCnt == 0){
        for(auto iter : mp){
            int half = iter.second / 2;
            for(int k = 0; k < half; k++){
                answer += iter.first;
            }
        }

        temp = answer;
        reverse(temp.begin(), temp.end());
        reverseAnswer = temp;

        answer = answer + reverseAnswer;
    }
    else{
        for(auto iter : mp){
            int half = iter.second / 2;
            for(int k = 0; k < half; k++){
                answer += iter.first;
            }
        }

        temp = answer;
        reverse(temp.begin(), temp.end());
        reverseAnswer = temp;

        answer = answer + oddChar;
        answer = answer + reverseAnswer;
    }

    cout << answer;
}