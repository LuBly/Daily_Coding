//[BaekJoon C++] 분해합 [브루트 포스]
#include <iostream>
#include <vector>

using namespace std;

int mkNum(int num){
    int result = num;
    while(num>0){
        result+=num%10;
        num/=10;
    }
    return result;
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int number;
    bool is_possible = false;
    cin >> number;
    for(int k=1; k<=number; k++){
        if(mkNum(k)==number){
            cout << k;
            is_possible = true;
            break;
        }
    }
    if(!is_possible) cout << 0;
}    