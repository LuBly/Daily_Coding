//[Programmers C++] 내적
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;   
    int tmp =0;
    for(int k=0;k<a.size();k++){
       tmp+=a[k]*b[k]; 
    }
    answer=tmp;
    return answer;
}