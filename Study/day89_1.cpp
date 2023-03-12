//[BaekJoon C++] 골드바흐 파티션 [약수, 배수와 소수, 더 빠르게]
#include <iostream>
#include <vector>
#define Max 1000001
using namespace std;

vector<bool> prime(Max,true);

void prime_vector(){
    prime[0]=false; prime[1]=false;

    for(int i=2;i*i<=Max;i++){//에라토스테네스의 체
        if(prime[i]){
            for(int j=i*2;j<=Max;j+=i) prime[j]=false;
        }
    }
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int count, num;
    prime_vector();

    cin>>count;
    for(int k=0;k<count;k++){//골드바흐 파티션 
        int answer = 0;
        cin>>num;
        for(int j=2;j<=num/2;j++){
            if(prime[j]&&prime[num-j]) answer++;
        }
        cout<<answer<<'\n';
    }
}    