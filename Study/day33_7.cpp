#include <string>
//[Programmers C++] 약수의 개수와 덧셈 
#include <vector>
using namespace std;
int div(int n){
    int count=0;
    for(int i=1; i*i<=n;i++){
        if(n%i==0){
            if(i*i==n) count++;
            else count +=2;
        }
    }
    return count;
}
int solution(int left, int right) {
    int answer = 0;
    for(int k=left; k<=right; k++){
        if(div(k)%2==0) answer+=k;
        else answer -=k;
    }
    return answer;
}