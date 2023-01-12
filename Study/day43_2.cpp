//[Programmers C++] k진수에서 소수 개수 구하기
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool is_prime(long long a){
    for(long long i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<long long> num;
    while(n>0){
        num.push_back(n%k);
        n/=k;
    }
    long long tmp=0;
    for(int p=num.size()-1;p>=0;p--){
        if(num[p]!=0){
            tmp+=num[p];
            if(num[p-1]!=0&&p>0) tmp*=10;
        }
        else{//0을 만났을 때
            if(is_prime(tmp)&&tmp>1) answer++;
            tmp=0;
        }
        //cout<<"tmp: "<<tmp<<" answer: "<<answer<<endl;
    }
    if(tmp>1&&is_prime(tmp)) answer++;
    //for(int b=0;b<num.size();b++) cout<<num[b]<<" ";
    return answer;
}