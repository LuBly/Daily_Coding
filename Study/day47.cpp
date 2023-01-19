//[Programmers C++] 2개 이하로 다른 비트
#include <string>
#include <vector>

using namespace std;

bool bit_check(long long org, long long ch){
    long long result = org^ch;
    int count = 0;
    while(result>0){
        if(result%2==1) count++;
        if(count>2) return false;
        result/=2;
    }
    return true;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int a=0;a<numbers.size();a++){
        long long orig = numbers[a];
        if(orig%2==0) answer.push_back(orig+1);
        else{
            long long bit=1;
            while(true){
                if((orig&bit) == 0) break;
                bit*=2;
            }
            bit=bit/2;
            answer.push_back(orig+bit);
        }
    }
    return answer;
}