//[Baekjoon C++] 공유기 설치 [이분탐색]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, C;
    cin >> N >> C;
    /*
    1 2 4 8 9
    */
    vector<int> data(N);
    for(int k = 0; k < N; k++){
        cin >> data[k];
    }    
    // 주어진 집들의 거리를 초기화
    sort(data.begin(), data.end());

    // 집들 사이의 거리를 초기화
    // 최소 거리 = 1, 최대거리 = 끝 집 - 처음 집
    int st = 1, end = data[N-1] - data[0], res = 0;

    // 집들 사이의 거리를 기준으로 이분 탐색 진행
    while(st <= end){
        int mid = (st + end) / 2;
        // 공유기가 원하는 만큼 설치되었는지 확인하기 위한 변수
        int cnt = 1;
        int prev = data[0];
        for(int k = 1; k < N; k++){
            if(data[k] - prev >= mid){
                cnt++;
                prev = data[k];
            }
        }

        // 공유기를 제한 개수 이상 사용했을 경우, 공유기 설치 거리를 늘린 후 다시 설치
        if(cnt >= C){
            res = max(res, mid);
            st = mid + 1;
        }
        // 공유기를 제한 개수 이하 사용했을 경우, 공유기 설치 거리를 줄인 후 다시 설치
        else{
            end = mid - 1;
        }
    }
    cout << res;
}