//[Baekjoon C++] 수열 [누적 합]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int Line_num,count,max;
    cin>>Line_num>>count;//입력되는 숫자의 수, 연속된 숫자의 수
    vector<int> intSum;
    int sum=0;
    for(int k=0;k<Line_num;k++){
        int input;
        cin>>input;
        sum+=input;
        intSum.push_back(sum);//0~k까지의 합을 계속해서 입력
    }

    for(int j=count-1;j<Line_num;j++){
        int start,end;
        if(j!=count-1){
            start=j-count;
            end=j;
            if(intSum[end]-intSum[start]>max) max=intSum[end]-intSum[start];
        }
        else max=intSum[j];
    }

    cout<<max;
}