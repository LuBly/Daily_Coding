//[Programmers C++] 카드 뭉치
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    for(int k=0;k<goal.size();k++){
        if(goal[k]==cards1[0]) cards1.erase(cards1.begin());
        else if(goal[k]==cards2[0]) cards2.erase(cards2.begin());
        else answer = "No";
    }
    
    return answer;
}