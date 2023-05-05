//[Baekjoon C++] 잃어버린 괄호 [그리디]
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string input;
    cin>>input;
    vector<char> cal;
    vector<int> num;
    // 더하기는 괄호로 묶어서 먼저 계산하고 - 나중에 계산
    // ex 55+50-(40+30)-(40+20)
    // ex 55+50-40 => 105 -40 =65, 
    // ex 5+50-50+5
    string tmp = "";
    for(int k=0;k<input.size();k++){
        if(input[k]=='+'){// + 일 때 앞 뒤의 숫자를 합쳐야한다. 따로 배열에 추가
            num.push_back(stoi(tmp));
            cal.push_back('+');
            tmp="";
        }
        else if(input[k]=='-'){// - 일 때 앞 뒤의 숫자를 빼야한다. 따로 배열에 추가
            num.push_back(stoi(tmp));
            cal.push_back('-');
            tmp="";
        }
        else{
            tmp+=input[k];
        }
    }
    num.push_back(stoi(tmp));
    vector<int> result;
    int n = num[0];
    for(int k=0;k<cal.size();k++){
        if(cal[k]=='-'){
            result.push_back(n);
            n=num[k+1];
        }
        else{
            n+=num[k+1];
        }
    }
    result.push_back(n);
    int answer=result[0];

    for(int k=1;k<result.size();k++){
        answer-=result[k];
    }
    cout<<answer;
}