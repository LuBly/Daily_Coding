//[Baekjoon C++] 합 구하기 [누적 합]
#include <iostream>
#include <vector>
using namespace std;
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int insert_cnt, check_cnt;
    int sum=0;
    vector<int> preSum;
    preSum.push_back(0);//편한 계산을 위해 preSum[0] 을 0으로 선입력.
    cin>>insert_cnt;
    for(int k=0;k<insert_cnt;k++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        preSum.push_back(sum);
    }

    cin>>check_cnt;
    for(int j=0;j<check_cnt;j++){//preSum 계산 pSum[end]-pSum[start-1];
        int start,end;
        cin>>start>>end;
        cout<<preSum[end]-preSum[start-1]<<'\n';
    }
}