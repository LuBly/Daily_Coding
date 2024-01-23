//[Baekjoon C++] 기타줄 [그리디] 12 10 ~ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int target, M;
    cin >> target >> M;
    // 6개 패키지 / 낱개 가격
    vector<int> package(M);
    vector<int> single(M);
    for(int k = 0; k < M; k++){
        cin >> package[k] >> single[k];
    }

    sort(package.begin(), package.end());
    sort(single.begin(), single.end());
    /*
    6개로 사는게 < 낱개 6개 사는거보다 저렴할 때
    */
    int answer = 0;
    while(target > 6){
        // 패키지 하나 사는게 single 6개보다 비쌀 때
        // 싱글로 구매
        if(package[0] > single[0] * 6){
            answer += single[0] * 6;
        }
        else{
            answer += package[0];
        }
        target -= 6;
    }

    if(package[0] > single[0] * target){
        answer += single[0] * target;
    }
    else
        answer += package[0];

    cout << answer;
}