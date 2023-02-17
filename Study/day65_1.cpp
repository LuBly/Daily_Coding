//[BaekJoon C++] 소트인사이드 [정렬]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    int num;
    vector<int> arr;
    cin>>num;
    while(num>0){
        arr.push_back(num%10);
        num/=10;
    }
    
    sort(arr.rbegin(),arr.rend());
    for(auto iter: arr)cout<<iter;
}