//[Baekjoon C++] 주유소 [그리디]
#include <iostream>
#include <vector>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cityCnt;
    cin >> cityCnt;

    //맨 왼쪽에서 제일 오른쪽으로 이동
    //idx 0 -> cityCnt-1;
    //기름통 무제한
    //기름 1리터당 노드 가격
    //다음 노드만 체크
    /*
    if 현재 노드 < 다음 노드
    {
        현재노드 가격으로 기름 사용.
    }
    else 현재 노드 > 다음 노드
    {
        다음노드 가격으로 기름 사용.
    }
    */
    vector<int> dist(cityCnt-1);
    for(int k = 0; k < cityCnt-1; k++){
        cin >> dist[k];
    }

    vector<int> city(cityCnt);
    for(int k = 0; k < cityCnt; k++){
        cin >> city[k];
    }

    int minCost = city[0];
    int res = dist[0] * minCost;
    /*
    ex)
    5 * 2 = 10
    2 * 3 = 6
    2 * 1 = 2

    */

    for(int k = 1; k < cityCnt-1; k++){
        int cost = city[k];
        if(cost < minCost){
            minCost = cost;
        }

        res += dist[k] * minCost;
    }
    cout << res;
}