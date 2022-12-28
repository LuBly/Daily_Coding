//[Programmers C++] 없는 숫자 더하기
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(int k=0;k<numbers.size();k++){
        answer-=numbers[k];
    }
    return answer;
}