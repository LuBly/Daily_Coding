//[Baekjoon C++] RGB거리 [DP]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int house[1001][3]={0,};
    int cost[3];//R G B 를 칠하는데 드는 비용
    int cnt;
    cin>>cnt;
    for(int k=1;k<=cnt;k++){
        cin>>cost[0]>>cost[1]>>cost[2];//R G B 를 칠하는데 드는 비용
        house[k][0] = min(house[k-1][1],house[k-1][2])+cost[0];//R로 색칠하는데 드는 비용
        house[k][1] = min(house[k-1][0],house[k-1][2])+cost[1];//G로 색칠하는데 드는 비용
        house[k][2] = min(house[k-1][0],house[k-1][1])+cost[2];//B로 색칠하는데 드는 비용
    }
    int answer = min({house[cnt][0],house[cnt][1],house[cnt][2]});
    cout<<answer;
}