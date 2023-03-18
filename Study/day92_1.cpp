//[BaekJoon C++] 부분합 [누적 합]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int size, target;
    cin>>size>>target;
    vector<int> preSum(size);
    
    for(int k=0;k<size;k++)//수행횟수 최대 100,000
        cin>>preSum[k];
    
    int start=0, end=0, sum=0, minLen=10000000;
    while(start<=end){
        if(sum>=target){//현재 포인터의 합이 target보다 크거나 같으면 start++
            minLen = min(minLen,end-start);//가장 짧은 길이만 저장
            sum-=preSum[start++];//현재 start에 해당하는 값을 삭제하고 start++
        }
        else if(end==size) break;//끝까지 탐색을 완료한 경우 종료
        else sum+=preSum[end++];//현재 end에 해당하는 값을 추가하고 end++
    }

    if(minLen == 10000000) cout<<0<<'\n';//불가능하면 0 출력
    else cout<<minLen<<'\n';

}    