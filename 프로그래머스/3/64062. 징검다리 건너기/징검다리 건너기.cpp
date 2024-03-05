#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*[이분탐색]
O(logN) 200,000,000 => 8 log 2
1~5
left 1 right 5
mid => 3 체크 (true) -> 다리를 건널 수 있음
answer = max(answer, mid);
left = 4, right = 5
mid => 4 체크 (false) -> 다리를 건널 수 없음
*/
bool binarySearch(vector<int> stones, int k, int mid){
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] < mid) cnt++;
        else cnt = 0;
        
        if(cnt >= k) return false;
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(binarySearch(stones, k, mid)){
            answer = max(answer, mid);
            left = mid + 1;
        }
        else{
            right  = mid - 1;
        }
    }
    return answer;
}