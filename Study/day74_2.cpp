//[BaekJoon C++] 베르트랑 공준 [수학]
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
	
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        int count=0;
        for(int k=n+1;k<=n*2;k++){
            if(is_prime(k)) count++;
        }
        cout<<count<<'\n';
    }
}