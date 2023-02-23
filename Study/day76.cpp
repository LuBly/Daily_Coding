//[BaekJoon C++] 신나는 함수 실행 [DP]
#include <iostream>
#include <map>
#include <algorithm>
#include <tuple>
using namespace std;

map<tuple<int, int, int>, int> dp;

int cal(int a, int b, int c){
    if(a<=0||b<=0||c<=0) return 1;
    else if(a>20||b>20||c>20) return cal(20,20,20);
    else if(dp[make_tuple(a,b,c)]!=0) return dp[make_tuple(a,b,c)];//map에 a,b,c 정보가 있으면 해당 정보 out
    else if(a<b && b<c) dp[make_tuple(a,b,c)] = cal(a,b,c-1)+cal(a,b-1,c-1)-cal(a,b-1,c);
    else dp[make_tuple(a,b,c)] = cal(a-1,b,c)+cal(a-1,b-1,c)+cal(a-1,b,c-1)-cal(a-1,b-1,c-1);
    return dp[make_tuple(a,b,c)];
}


int main() {
    ios::sync_with_stdio(false);
    while(true){
        int j,q,k;
        int result;
        cin>>j>>q>>k;
        if(j==-1&&q==-1&&k==-1) break;
        cout<<"w("<<j<<", "<<q<<", "<<k<<") = "<<cal(j,q,k)<<'\n';
    }

}