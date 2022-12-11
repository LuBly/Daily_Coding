//[Programmers C++] 최대값과 최솟값
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    string stringBuffer;
    vector<int> num;
    vector<string> numToS;
    while (getline(ss, stringBuffer, ' '))
    {
        int tmp;
        stringstream ssInt(stringBuffer);
        ssInt >> tmp;
        num.push_back(tmp);
    }
    
    sort(num.begin(),num.end());
    
    for(int k=0;k<num.size();k++){
        numToS.push_back(to_string(num[k]));
    }
    answer.append(numToS[0]);
    answer.append(" ");
    answer.append(numToS[numToS.size()-1]);
    
    return answer;
}
