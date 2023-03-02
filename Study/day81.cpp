//[BaekJoon C++] 서로 다른 부분 문자열의 개수 [집합과 맵]
#include <iostream>
#include <map>

using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int A,B;
    int answer=0;
    map<int,int> stm_diff;//숫자, count >>count 가 1인 경우만 answer++; 최대 연산 40만

    cin>>A>>B;
    for(int k=0;k<A;k++){//기준 점 입력
        int numA;
        cin>>numA;
        stm_diff[numA]++;
    }

    for(int j=0;j<B;j++){//비교 대상 입력하면서 중복되는 결과값들 삭제
        int numB;
        cin>>numB;
        stm_diff[numB]++;
    }

    for(auto iter:stm_diff){
        if(iter.second==1) answer++;
    }
    cout<<answer;
}