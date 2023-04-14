//[Baekjoon C++] 거스름돈 [그리디]
#include <iostream>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int payment, left, answer=0, st=0;
    int money[6] = {500,100,50,10,5,1};
    cin>>payment;
    left = 1000-payment;//620->120->20->0

    while(left!=0){
        int idx=0;
        
        for(int k=st;k<5;k++){
            if(left/money[k]==0){
                idx=k+1;
                st++;
                break;
            }
        }
        int cnt = left/money[idx]; //거스름돈으로 사용된 동전의 갯수
        answer += cnt; 
        left-= cnt*money[idx];
    }
    cout<<answer;
}