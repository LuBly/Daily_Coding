//[BaekJoon C++] 설탕 배달 [브루트 포스]
#include <iostream>
#include <vector>

using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num, result=3000;
    bool can_make=false;
    cin>>num;

    for(int k=0; k<2000; k++){//3키로 설탕 갯수
        for(int j=0; j<2000; j++){//5키로 설탕 갯수
            int sugar = 3*k+5*j;
            if(sugar==num){
                int count = j+k;
                can_make=true;
                if(count<result) result=count;
            }
            if(sugar>5000) break;
        }
    }
    if(!can_make) cout<<-1;
    else cout<<result;
}    