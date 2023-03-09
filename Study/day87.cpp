//[BaekJoon C++] 영화감독 숌 [브루트 포스]
#include <iostream>
#include <string>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num;
    string tmp;
    int cnt=0;
    int result=666;
    cin >> num;
    while(true){
        tmp = to_string(result);
        for(int k=0; k<tmp.size()-2;k++){
            if(tmp[k]=='6' && tmp[k+1]=='6' && tmp[k+2]=='6'){
                cnt++;
                break;
            }
        }
        if(cnt==num) break;
        result++;           
    }

    cout<<result;
}    