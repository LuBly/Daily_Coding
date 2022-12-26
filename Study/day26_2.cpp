//[Prgrammers C++] x만큼 간격이 있는 n개의 숫자
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long num = x;
    answer.push_back(x);
    for(int k =1; k<n;k++){
        num += x;
        answer.push_back(num);
    }
    return answer;
}