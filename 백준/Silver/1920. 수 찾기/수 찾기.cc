//[BaekJoon C++] 수 찾기 [이분탐색]
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int aCnt, numCnt;
vector<int> arr(MAX);

void binarySearch(int num){
    int start = 0;
    int end = aCnt - 1;
    int mid;
    while(end >= start){
        mid = (start + end) / 2;

        if(arr[mid] == num){
            cout << 1 << '\n';
            return;
        }
        // 찾으려는 값이 배열의 중앙값 보다 작을 때 end 포인터 위치를 변경
        else if(arr[mid] > num){
            end = mid - 1;
        }
        // 찾으려는 값이 배열의 중앙값 보다 클 때 start 포인터 위치를 변경
        else{
            start = mid + 1;
        }
    }

    cout << 0 << '\n';
    return;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> aCnt;
    for(int k = 0; k < aCnt; k++){
        cin >> arr[k];
    }
    sort(arr.begin(), arr.begin() + aCnt);

    cin >> numCnt;
    /*
    오름차순 정렬을하고
    binary search
    */
    for(int k = 0; k < numCnt; k++){
        int num;
        cin >> num;

        binarySearch(num);
    }
    
}   
