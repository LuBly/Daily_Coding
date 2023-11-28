//[Baekjoon C++] 회전 초밥 [투포인터]
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, D, K, C;
    cin >> N >> D >> K >> C;

    vector<int> belt(N);
    for(int k = 0; k < N; k++){
        cin >> belt[k];
    }

    /*
    7 9 7 30 2 7 9 25
    K만큼 슬라이드로 이동하면서 체크?
    */
    int st = 0, end = K-1;
    map<int,int> resData;
    resData[C] = 1;
    
    int curCnt = 1;
    for(int k = 0; k < K; k++){
        int cur = belt[k];
        if(resData[cur] == 0) curCnt++;
        resData[cur]++;
    }
    int maxCnt = curCnt;
    while(true){
        int curSt = belt[st++ % N];
        int curEnd = belt[++end % N];

        // curSt는 빠지고
        resData[curSt]--;
        if(resData[curSt] == 0) curCnt--;
        // curEnd는 추가
        if(resData[curEnd] == 0) curCnt++;
        resData[curEnd]++;

        //cout << "curSt : "<<curSt<< " curEnd : " << curEnd << " result : " <<curCnt <<endl;
        maxCnt = max(maxCnt, curCnt);
        if(st % N == 0) break;
    }
    cout << maxCnt;

}