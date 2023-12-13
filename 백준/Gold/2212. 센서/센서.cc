//[Baekjoon C++] 센서 [그리디]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;

    vector<int> Sensors(N);
    vector<int> Diff(N);
    for(int k = 0; k < N; k++){
        cin >> Sensors[k];
    }
    sort(Sensors.begin(), Sensors.end());

    // 1 3 6 7 9
    // 2 3 1 2
    // 1 2 /2(K=3) /3(K=2) /(K=1)
    for(int k = 1; k < N; k++){
        Diff[k-1] = Sensors[k] - Sensors[k-1];
    }

    sort(Diff.begin(), Diff.end());

    int ans = 0;
    for(int k = 0; k < N - K + 1; k++){
        ans += Diff[k];
    }

    cout << ans;
}