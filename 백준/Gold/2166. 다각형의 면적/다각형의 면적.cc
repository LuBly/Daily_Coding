//[Baekjoon C++] 다각형의 면적 [기하]
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long double outer_product(pair<long long,long long> x, pair<long long, long long> y){
    return x.first*y.second-x.second*y.first;
}

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt;
    cin>>cnt;
    vector<pair<int,int>> pt;
    //point 입력받기
    for(int k=0;k<cnt;k++){
        int a,b;
        cin>>a>>b;
        pt.push_back({a,b});//x,y좌표
    }
    //외적을 통한 다각형의 면적 계산
    //시작점을 기준으로 나머지 두개의 점들을 외적하여 삼각형의 넓이들을 구하고 이를 전부 합해준다.
    long double answer = 0;
    for(int k=1;k<cnt-1;k++){
        answer+=outer_product(
            {pt[k].first-pt[0].first,pt[k].second-pt[0].second},
            {pt[k+1].first-pt[0].first,pt[k+1].second-pt[0].second}
        )/2;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<abs(answer);
}