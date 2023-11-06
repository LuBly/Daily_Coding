//[Baekjoon C++] Yonsei TOTO [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<int> res;
    for(int k = 0; k < N; k++){
        int P, L;
        cin >> P >> L;

        // P가 L보다 작을 경우 무조건 1mil로 수강하는 것이 이득
        // P가 L보다 크거나 같을 경우
        /*
        ex) 5, 4
        5명 지원 4명까지 받아준다. 상위 4명
        36 36 36 "25" 1
        -> mil정보를 sort하고 위에서 4번째 인원과 동일한 점수를 배당한다고 가정
        1번과목 25
        2번과목 20
        3번과목 36
        4번과목 1
        5번과목 15

        -> 각 과목별 투자 마일리지를 오름차순 정렬
        1 15 20 25 36
        누적합 
        1 16 36 51<<여기까지 수강 가능// 87
        */

        vector<int> subjectData(P);
        for(int j = 0; j < P; j++){
            cin >> subjectData[j];
        }
        
        if(P < L){
            res.push_back(1);
        }
        else{
            sort(subjectData.rbegin(), subjectData.rend());
            res.push_back(subjectData[L-1]);
        }       
    }

    sort(res.begin(), res.end());
    int sum = 0;
    int answer = 0;
    for(int k = 0; k < N; k++){
        sum += res[k];
        if(sum <= M){
            answer++;
        }
        else break;
    }

    cout << answer;
}