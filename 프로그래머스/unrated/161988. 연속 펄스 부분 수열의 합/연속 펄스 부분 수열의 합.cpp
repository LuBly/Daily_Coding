#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int sz = sequence.size();
    vector<long long> dp1(sz,0);
    vector<long long> dp2(sz,0);
    vector<int>seq1(sz,0);
    vector<int>seq2(sz,0);
    for(int k=0;k<sz;k++){//1 -1 1 -1 펄스로 진행
        seq1[k] = sequence[k];
        if(k%2!=0)
            seq1[k]*= -1;
    }
    for(int k=0;k<sz;k++){//-1 1 -1 1 펄스로 진행
        seq2[k] = sequence[k];
        if(k%2==0)
            seq2[k]*= -1;
    }
    if(sz==1){
        answer = max(seq1[0],seq2[0]);
        return answer;
    }
    //1 -1 1 펄스일 때, -1 1 -1 펄스일 때 최대값 비교
    dp1[0]=seq1[0];
    dp2[0]=seq2[0];
    for(int k=1;k<sz;k++){
        dp1[k] = max(dp1[k-1]+seq1[k],(long long)seq1[k]);
        answer = max(answer,dp1[k]);
    }

    for(int k=1;k<sz;k++){
        dp2[k] = max(dp2[k-1]+seq2[k],(long long)seq2[k]);
        answer = max(answer,dp2[k]);
    }
        
    return answer;
}