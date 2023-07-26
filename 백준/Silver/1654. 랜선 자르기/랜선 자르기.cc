//[Baekjoon C++] 랜선 자르기 [이분 탐색]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int K,N;
    cin>>K>>N;

    vector<long long> data;
    long long ans = 0;
    for(int k=0;k<K;k++){
        int a;
        cin>>a;
        data.push_back(a);
    }
    //오름차순 정렬
    sort(data.begin(),data.end());
    //min, max, mid를 계산
    long long left = 1, right = data.back(), mid;
    while(left<=right){
        //나누는 길이
        mid = (left+right)/2;
        long long cur=0;
        for(int k=0;k<K;k++){
            cur+=data[k]/mid;
        }
        if(cur>=N){
            // 현재 mid를 나눈 값이 N보다 크거나 같다면
            // left를 움직여 길이가 더 긴 경우는 없는지 확인
            left = mid+1;
            ans = max(ans,mid);
        }
        else{
            // 현재 mid로 나눈 값이 N보다 작다면
            // right를 움직여 길이가 더 짧은 경우는 가능한지 확인
            right = mid-1;
        }
    }
    cout<<ans;
}