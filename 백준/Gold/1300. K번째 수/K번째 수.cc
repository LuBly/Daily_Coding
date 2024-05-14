//[Baekjoon C++] K번째 수 [이분탐색]
#include <iostream>
using namespace std;
typedef long long LL;

LL answer;

void findValue(int n, int k, LL low, LL high){
    LL mid = (low + high)/2; // 이분탐색을 위한 mid값
    LL smallCount = 0; // k보다 작은 값들의 수
    LL temp;

    if(low <= high){
        // 최소값 계산
        for(LL layer = 1; layer <= n; layer++){
            temp = mid / layer;
            if(temp > n) temp = n;
            smallCount += temp;
        }

        // 더이상 조사할 구간이 없을 떄 결과 값 리턴
        if(low == high) {
            answer = low;
            return;
        }

        
        /*
            ex) 찾고자 하는 값이 7 일때 (n = 3)
            low = 1, high = 9
            mid = 5, count(mid = 5) => 5/3 + 5/2 + 5/1 = 1 + 2 + 3 = 6
            >> count가 원하는 값(7)보다 작다 그럼 더 큰 값을 찾아봐야한다 (RightBound)
            low 6, high = 9
            mid = 7, count(mid = 7) => 7/3 + 7/2 + 7/1 = 2 + 3 + 3 = 8
            >> count가 원하는 값(7)보다 크다 그럼 다 작은 값을 찾아봐야한다. (LeftBound)
            low 6, high 6
            >> low == high 종료
        */
        // k보다 작은 값들의 개수가 적다면 RightBound로 이동 
        if(smallCount < k){
            findValue(n, k, mid + 1, high);
        }
        // k보다 작은 값들의 개수가 많다면 LeftBound로 이동
        else{
            findValue(n, k, low, mid);
        }
    }
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    /*
    B[k] = Ans라고 할 때, Ans의 경우 반드시 1 ~ N*N 사이의 값을 가진다.
    1) 이 점을 토대로 정해져 있는 k를 찾아가보자.
    다만 같은 B[k-1] = Ans, B[k] = Ans인 경우가 있을 수 있다.
    -> 따라서 추가 조건 2)"B[k] = Ans 라는 것은 Ans값보다 작거나 같은 원소의 개수가 최소 k개가 존재한다" 부여
    작거나 같은 원소의 갯수는 어떻게 판단하는가? 

    4 8 12 16 
    3 6 9 12   => 1 2 3 4의 구조에 *2 *3 *4된 모습을 띄고있음을 알 수 있다.
    2 4 6 8
    1 2 3 4

    Answer = 6이라 가정해보면
    1 2 3 4 => 4개 (1,2,3,4) 6 / 1 => 4
    2 4 6 8 => 3개 (2,4,6) 6 / 2 = 3
    3 6 9 12 => 2개 (3,6) 6 / 3 = 2
    4 8 12 16 => 1개 (4) 6 / 4 = 1
    >> min((Ans / layer), n) 들의 합이 k 일 때를 반복(더 이상 나타나지 않을때까지)해서 계산해준다.
    */

    LL n, k;
    cin >> n >> k;
    findValue(n, k, 1, n*n);

    cout << answer;
}


