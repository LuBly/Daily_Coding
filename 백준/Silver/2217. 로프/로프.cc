//[Baekjoon C++] 로프 [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN 0;
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    vector<int> lines(N);
    for(int k = 0; k < N; k++){
        cin >> lines[k];
    }

    sort(lines.begin(), lines.end());
    int res = MIN;
    for(int k = 0; k < N; k++){
        int min = lines[lines.size() - 1 - k];
        res = max(res, min * (k + 1));
    }

    cout << res;


    /*
    w = Rope * k
    1 4 9 10 15 

    1개 => 15
    2개 => 10, 15 -> 20
    3개 => 9 10 15 -> 27
    4개 => 4 9 10 15 -> 16
    5개 => 5


    1개
    2개
    3개 
    4개
    5개
    ~~
    9999개 <최소값 x 9999>
    10000개 <최소값 x 10000>
    */
}