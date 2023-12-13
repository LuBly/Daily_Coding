//[Baekjoon C++] 주식 [그리디]
#include <iostream>
#include <vector>
using namespace std;
/*
주식 하나를 산다
원하는 만큼 가지고 있는 주식을 판다
아무것도 안한다

언제 사고 언제 팔건가

*/
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    for(int k = 0; k < T; k++){
        int N;
        cin >> N;

        vector<int> stock(N);
        for(int j = 0; j < N; j++){
            cin >> stock[j];
        }
        
        vector<int> m(N);
        m[N-1] = N-1;
        // d 부터 n-1일까지 중 가장 주가가 높은 날 저장.
        for(int day = N - 2; day >= 0; day--){
            if(stock[day] > stock[m[day + 1]]) m[day] = day;
            else m[day] = m[day + 1];
        }

        long long ans = 0;
        for(int day = 0; day < N; day++){
            //stock[d] < stock[m]인 m 이 존재하면, d에 주식을 사고 m 일에 주식을 판다.
            if(stock[day] < stock[m[day]]){
                ans += stock[m[day]] - stock[day];
            }
        }

        cout << ans << '\n';
    }
}