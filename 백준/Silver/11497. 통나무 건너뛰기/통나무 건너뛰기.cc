//[Baekjoon C++] 통나무 건너뛰기 [정렬]
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;



int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int testCase;
    cin>>testCase;
    // 가장 낮은 난이도는 어떻게 설정할 것인가?
    // 2 4 5 7 9
    // 10 10 11 11 12 12 13 
    // 가장 큰 값을 가운데에 놓고 좌우로 하나씩 값을 배치
    // 홀수 idx => 오름차순으로 먼저 배치
    // 짝수 idx => 내림차순으로 나중에 배치
    // 이후 간차가 가장 큰 것 result
    // 25974
    for(int k=0;k<testCase;k++){
        int cnt;
        cin>>cnt;
        vector<int> data(cnt,0);
        vector<int> res;
        for(int j=0;j<cnt;j++)
            cin>>data[j];
        sort(data.begin(),data.end());//내림차순 정렬
        for(int i=0;i<cnt;i++){//정순
            if(i%2==0) res.push_back(data[i]);
        }
        for(int i=cnt-1;i>0;i--){//역순
            if(i%2==1) res.push_back(data[i]);
        }
        int minValue = 0;
        for(int i=1;i<cnt;i++){
            int tmp = abs(res[i]-res[i-1]);
            minValue = max(minValue, tmp);
        }
        cout<<minValue<<'\n';
    }
}