//[BaekJoon C++] 동전 0 [그리디 알고리즘]
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    int count, limit, num;
    int answer=0;
    vector<int> coin;
    cin>>count>>limit;
    for(int k=0;k<count;k++){
        cin>>num;
        coin.push_back(num);
    }

    for(int j=coin.size()-1;j>=0;j--){//뒤에서부터 나누면서 나눠지면 갯수 ++
        if(limit/coin[j]>0){
            answer+=limit/coin[j];
            limit%=coin[j];
        }
    }

    cout<<answer;
}