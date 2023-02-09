//[BaekJoon C++] 통계학 [정렬]
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(pair<int,int> A, pair<int,int> B){
    if(A.first!=B.first) return A.first>B.first;
    else return A.second<B.second;
}

int main(void){
    ios::sync_with_stdio(false);
    int count, middle, range, M_freq;
    int avg=0;
    int N_cnt=1;
    double sum=0;
    vector<int> number;
    vector<pair<int, int>> freq;//빈도, 숫자
    cin>>count;
    for(int k=0;k<count;k++){
        int num;
        cin>>num;
        number.push_back(num);
        sum+=num;
    }
    sort(number.begin(),number.end());
    for(int j=0;j<number.size();j++){
        if(j>0){
            if(number[j]==number[j-1]){
                N_cnt++;
            }
            else{
                freq.push_back(make_pair(N_cnt,number[j-1]));
                N_cnt=1;
            }
        }
    }
    freq.push_back(make_pair(N_cnt,number.back()));

    sort(freq.begin(),freq.end(),cmp);
    if(freq[0].first==freq[1].first) M_freq=freq[1].second;
    else M_freq=freq[0].second;

    middle=number[number.size()/2];
    range=number.back()-number.front();
    avg=(int)floor((sum/count)+0.5);//반올림 하는 함수 floor _#include <cmath>
    cout<<avg<<'\n'<<middle<<'\n'<<M_freq<<'\n'<<range;
}