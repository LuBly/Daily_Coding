//[Baekjoon C++] 나머지 합 [누적 합]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
/*
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll Num_count,Div;
    ll tmp=0,answer=0;
    vector<ll> sum;
    
    cin>>Num_count>>Div;
    for(ll k=0;k<Num_count;k++){
        ll num;
        cin>>num;
        tmp+=num;
        sum.push_back(tmp%Div);//누적 합%Div 값을 sum 백터에 저장
    }

    answer+=count(sum.begin(),sum.end(),0);//결과 값이 0인 경우 그 자체로 개수 추가이므로 미리 + 해둠
    for(ll j=0;j<Div;j++){//(sum[j]-sum[i-1])%Div = 0 >> sum[j]%Div==sum[i-1]%Div 로 계산.
        ll cnt=count(sum.begin(),sum.end(),j); << count 대신 vector의 idx를 사용하면 좀 더 빠른 계산이 될 것으로 보임
        answer+=cnt*(cnt-1)/2;
    }

    cout<<answer;
}
*///시간 줄이기 작업
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll Num_count,Div;
    ll tmp=0,answer=0;

    cin>>Num_count>>Div;
    vector<ll> sum(Div,0);//moduler 결과 값은 Div보다 항상 작을것이기 때문에 Div Size의 벡터를 생성하고 0으로 초기화
    for(ll k=0;k<Num_count;k++){
        ll num;
        cin>>num;
        tmp+=num;
        sum[tmp%Div]++;//moduler 결과값을 idx로 해서 갯수 확인
    }
    
    answer+=sum[0];
    for(ll j=0;j<Div;j++)
        answer+=(sum[j]*(sum[j]-1))/2;
    
    cout<<answer;
}