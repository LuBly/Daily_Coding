//[LCT C++] 문자열 뒤집기 [그리디 알고리즘] 313p(158), 정답 506p(255)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string input;
    cin>>input;
    //ABA
    //B
    //BABABABAB
    //BABAB
    // tmp의 길이가 1이라면 0 return
    // 이외에는 둘 중 적은 숫자를 return
    string tmp = "";
    bool is_fin = false;
    int Z_cnt=0, F_cnt=0;
    for(int k=1;k<input.size();k++){
        if(input[k]!=input[k-1]){
            is_fin = true;
            if(input[k-1]=='0')
                Z_cnt++;
                //tmp+='A';
            else
                F_cnt++;
                //tmp+='B';
            if(k==input.size()-1){//끝에서 숫자가 바뀌는 경우 체크
                if(input[k]=='0')
                    Z_cnt++;
                    //tmp+='A';
                else
                    F_cnt++;
                    //tmp+='B';
            }
        }
        else
            is_fin = false;
        
    }
    if(!is_fin){//끝 자리가 00 11 과 같이 위 반복문에서 처리할 수 없는 문자 체크용
        if(input.back()=='0') Z_cnt++;//tmp+='A';
        else F_cnt++;//tmp+='B';
    }
    if(F_cnt==0||Z_cnt==0) cout<<0;
    else
        cout<<min(F_cnt,Z_cnt);
    
}
