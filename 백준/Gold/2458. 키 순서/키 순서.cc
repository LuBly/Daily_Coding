//[Baekjoon C++] 키 순서 [플로이드 워셜]
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // studentCnt  : 학생들의 수
    // cmpCnt      : 두 학생의 키를 비교한 횟수
    // studentData : 각자의 키가 몇 번째인지 확인 할 그래프 데이터
    int studentCnt, cmpCnt;
    cin >> studentCnt >> cmpCnt;
    vector<vector<int>> studentData(studentCnt+1,vector<int>(studentCnt+1,INF));


    for(int k = 0; k < cmpCnt; k++){
        int from, to;
        cin >> from >> to;
        studentData[from][to] = 1;
    }

    for(int adj = 1; adj <= studentCnt; adj++){
        for(int from = 1; from <= studentCnt; from++){
            for(int to = 1; to <= studentCnt; to++){
                studentData[from][to] = min(studentData[from][to], studentData[from][adj] + studentData[adj][to]);
            }
        }
    }

    int answer = 0;
    for(int from = 1; from <= studentCnt; from++){
        int cnt = 0;
        for(int to = 1; to <= studentCnt; to++){
            // 자기보다 큰 사람 or 작은 사람이 존재하면 cnt++
            if(studentData[from][to] != INF || studentData[to][from] != INF){
                cnt++;
            }
        }
        // 순서를 알 수 있는 사람이 본인을 제외한 모두라면 answer++
        if(cnt == studentCnt - 1) answer++;
    }

    cout << answer;
}