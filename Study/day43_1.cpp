//[Programmers C++] n^2 배열 자르기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long a=left;a<=right;a++){
        int x = a%n; //x축
        int y = a/n; //y축
        
        if(x>y) answer.push_back(x+1);
        else answer.push_back(y+1);
    }
    return answer;
}