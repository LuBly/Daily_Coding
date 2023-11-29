//[Baekjoon C++] 좋다 [이분탐색]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
    cin >> N;

    vector<int> arr(N);
    for(int k = 0; k < N; k++){
        cin >> arr[k];
    }
    sort(arr.begin(), arr.end());
    /*
    st ? end ? mid ?
    판단 기준은?
    2000 * 2000 = 4,000,000
    1 2 3 4 5 6 7 8 9 10
    */
    int answer = 0;
    for(int k = 0; k < N; k++){
        //이분 탐색 시작
        int st = 0, ed = N-1;
        while(st < ed){
            if(st == k){
                st++;
                continue;
            }
            if(ed == k){
                ed--;
                continue;
            }
            int sum = arr[st] + arr[ed];
            if(arr[k] > sum) st++;
            else if(arr[k] == sum){
                answer++;
                break;    
            }
            else ed--;
        }
    }

    cout << answer;
}