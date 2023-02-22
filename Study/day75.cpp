//[BaekJoon C++] 골드바흐의 추측 [수학]
#include <iostream>
using namespace std;

bool is_prime(int num){
    if(num==1) return false;
    if(num==2||num==3) return true;

    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int count;
    cin>>count;
    for(int k=0;k<count;k++){
        int input;
        int a,b;
        cin>>input;
        for(int j=2;j<=input/2;j++){
            if(is_prime(j)&&is_prime(input-j)){
                a=j;
                b=input-j;
            }
        }
        cout<<a<<" "<<b<<'\n';
    }
}