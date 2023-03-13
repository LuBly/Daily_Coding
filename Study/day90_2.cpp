//[BaekJoon C++] 숫자 카드 2 [집합과 맵]
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    map<int,int> card;
    cin>>N;
    for(int k=0;k<N;k++){
        int num;
        cin>>num;
        card[num]++;
    }
    cin>>M;
    for(int j=0;j<M;j++){
        int input;
        cin>>input;
        cout<<card[input]<<" ";
    }
}    