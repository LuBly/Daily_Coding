//[BaekJoon C++] 수들의 합 [투 포인터]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int size, target;
    cin>>size>>target;
    vector<int> num(size);
    for(int k=0;k<size;k++)
        cin>>num[k];
    
    int start=0, end=0, count=0, sum=0;
    while(start<=end){
        if(sum>=target) sum-=num[start++];
        else if(end==size) break;
        else sum+=num[end++];

        if(sum==target) count++;
    }
    cout<<count;   
}    