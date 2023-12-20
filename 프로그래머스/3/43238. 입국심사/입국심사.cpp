#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//log N = 9
//O(N) = 900,000

/*
st = 1, end = 가장 오래걸리는 팀 * 인원수

while(st <= end){
    mid = (st + end) / 2
    int tmp = 0;
    for(auto iter : times){
        tmp += iter / mid;
    }
    
    if(tmp >= n){
        end = mid - 1;
        answer = mid;
    }
    else{
        st = mid + 1;
    }
}

*/

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long st = 1, end = n * (long long)times.back();
    while(st <= end){
        long long mid = (st + end) / 2;
        long long tmp = 0;
        
        for(int k = 0; k < times.size(); k++){
            tmp += (mid / (long long)times[k]);
        }
        
        if(tmp >= n){
            end = mid - 1;
            answer = mid;
        }
        else
            st = mid + 1;
            
    }
    
    return answer;
}