#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int,int>> part;
    int st=0, dt=0, sum=sequence[0];//시작 cur과 끝 cur, 최초 결과 값 저장 
        
    //st를 기준으로 계속 반복, 추가 시키면서 체크
    while(st<sequence.size()){
        if(sum<k){
            if(dt==sequence.size()-1)//끝 자리일 경우
                sum-=sequence[st++]; 
            else
                sum+=sequence[++dt];
        }
        else if(sum>k){
            sum-=sequence[st++];
        }
        else if(sum==k){
            part.push_back(make_pair(st,dt));
            sum-=sequence[st++];
        }
    }
    
    int min=1000000, ms, md;
    for(auto iter:part){
        int length=iter.second-iter.first;
        //cout<<length<<" "<<min<<endl;
        if(length<min){//최소값이 바뀔 경우, 같을 경우엔 처음 들어온 값이 계속 유지됨
            ms=iter.first;
            md=iter.second;
            min = length;
        }
    }
    answer.push_back(ms); answer.push_back(md);
    return answer;
}