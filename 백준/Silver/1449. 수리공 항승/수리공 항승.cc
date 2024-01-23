//[Baekjoon C++] 수리공 항승 [그리디] 12 25
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt, L;
    cin >> cnt >> L;
    
    vector<int> pipe(cnt);
    for(int k = 0; k < cnt; k++){
        cin >> pipe[k];
    }

    sort(pipe.begin(), pipe.end());
    int cur = pipe[0];
    int answer = 1;
    for(int k = 1; k < cnt; k++){
        if(pipe[k] < cur + L) continue;
        else{
            cur = pipe[k];
            answer++;
        }
    }

    cout << answer;
}