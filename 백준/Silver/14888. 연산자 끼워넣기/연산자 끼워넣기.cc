//[Baekjoon C++] 연산자 끼워넣기 [구현]
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int resMax = -1000000001;
int resMin = 1000000001;
int numCount;
vector<int> nums(11);
vector<int> op(4);

void dfs(int idx, int result){

    if(idx==numCount){
        resMax = max(resMax, result);
        resMin = min(resMin, result);
        return;
    }

    for(int k = 0; k < 4; k++){
        if(op[k]>0){
            op[k]--;
            if(k==0){
                dfs(idx+1, result + nums[idx]);
            }
            else if(k==1){
                dfs(idx+1, result - nums[idx]);
            }
            else if(k==2){
                dfs(idx+1, result * nums[idx]);
            }
            else{
                dfs(idx+1, result / nums[idx]);
            }
            op[k]++;
        }
    }

}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);    
    cin >> numCount;

    // 숫자 입력받기
    for(int k = 0; k < numCount; k++){
        cin >> nums[k];
    }

    // 연산자 입력받기
    // + - x /
    for(int k = 0; k < 4; k++){
        cin >> op[k];
    }

    dfs(1, nums[0]);

    cout << (int)resMax << '\n' << (int)resMin;
}