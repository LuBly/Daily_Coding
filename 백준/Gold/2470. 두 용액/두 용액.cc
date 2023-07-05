//[Baekjoon C++] 두 용액 [정렬]
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000000001
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt;
    cin>>cnt;
    vector<int> nums(cnt);
    for(int k=0;k<cnt;k++)
        cin>>nums[k];
    
    sort(nums.begin(),nums.end());
    int min_res = MAX, start = 0, end = cnt-1;
    int res_A,res_B;
    //-99 -2 -1 4 98
    //투포인터로 접근
    while(start<end){
        int sum = nums[start] + nums[end];
        if(abs(sum)<min_res){
            res_A=nums[start];
            res_B=nums[end];
            min_res=abs(sum);
        }
        if(sum<0) start++;
        else end--;
    }
    if(res_A<res_B)
        cout<<res_A<<" "<<res_B;
    else    
        cout<<res_B<<" "<<res_A;
}
