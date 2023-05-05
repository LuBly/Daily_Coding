//[LCT C++] 만들 수 없는 금액 [그리디 알고리즘] 314p(158), 정답 509p(256)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1 1 2 3 9
// 1원 1
// 2원 2
// 3원 3
// 4원 1 1 2
// 5원 2 3
// 6원 1 2 3
// 7원 1 1 2 3
// 8원 
int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt, target = 1;
    vector<int> nums;
    cin>>cnt;
    for(int k=0;k<cnt;k++){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(),nums.end());
    for(auto iter : nums){
        if(target < iter) break;
        target+=iter;
    }
    cout<<target;
}
