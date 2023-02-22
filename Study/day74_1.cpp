//[Programmers C++] 모음사전
#include <string>
#include <vector>
using namespace std;

string words = "AEIOU";
int answer,cnt;

void dfs(string now, string target)
{
    if (now == target) answer = cnt;
    //word의 길이는 5이하
    if (now.length() > 5) return; 
    cnt++;
    for (int i = 0; i < words.length(); i++)
        dfs(now + words[i], target);
}

int solution(string word) {
    dfs("", word);
    return answer;
}