//[Programmers C++] 가장 큰 수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a,string b){
    return a+b>b+a; // a+b가 더 큰 순서대로 정렬
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for(int k=0;k<numbers.size();k++){
        tmp.push_back(to_string(numbers[k]));
    }
    sort(tmp.begin(),tmp.end(),cmp);
    if(tmp.front()=="0") return "0";
    for(int j=0;j<tmp.size();j++){
        answer+=tmp[j];
    }
    return answer;
}