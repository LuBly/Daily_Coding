#include <string>
#include <vector>
#define MAX 10000000
using namespace std;
//약수 중 최대 값을 계산

vector<int> solution(long long begin, long long end) {
    //숫자의 범위 1 ~ 10,000,000
    //본인을 제외한 약수 중 가장 큰 수 (10,000,000)보다는 작은 수
    vector<int> answer(end-begin+1,0);
    
    for(int k=begin;k<=end;k++){
        int max = 0;
        for(int i=2;i*i<=k;i++){
            if(k%i==0){
                if(k/i<=MAX)
                    (k/i) > max ? max = k/i : max = max;
                else
                    i>max ? max = i : max = max;
            }
        }
        
        answer[k-begin]=max;
        
        if(answer[k-begin]==0){
            answer[k-begin]=1;
        }
    }
    if(begin==1) answer[0]=0;
    return answer;
}