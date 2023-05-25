//[LCT C++] 럭키 스트레이트 [구현] 321p(162), 정답 515p(259)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string input;
    cin>>input;
    int sz = input.size();
    int front = 0, back = 0;
    for(int k=0;k<sz/2;k++){
        front+=(input[k]-'0');
    }
    for(int k=sz/2;k<sz;k++){
        back+=(input[k]-'0');
    }
    if(front == back)
        cout<<"LUCKY";
    else
        cout<<"READY";
}
