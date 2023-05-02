//[LCT C++] 곱하기 혹은 더하기 [그리디 알고리즘] 312p(157), 정답 506p(255)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string input;
    vector<int> num;
    cin>>input;
    // 입력된 문자열을 숫자로 변환하여 벡터에 저장
    // 내림차순 정렬_구지 할 필요가 없다.
    // -> 시간 복잡도 이득
    // 하나씩 순환하며 두 숫자의 합이 곱보다 클 경우 합, 작을 경우 곱셈을 진행
    // -> 합이 곱보다 큰 경우(계산하고자 하는 두 수 중 하나라도 0 혹은 1인 경우)
    for(int k=0;k<input.size();k++){
        int cur = input[k]-'0';
        num.push_back(cur);
    }
    
    int answer=num[0];
    for(int k=1;k<num.size();k++){
        if(num[k]<=1||answer<=1)
            answer+=num[k];
        else
            answer*=num[k];
    }
    cout<<answer;
}
