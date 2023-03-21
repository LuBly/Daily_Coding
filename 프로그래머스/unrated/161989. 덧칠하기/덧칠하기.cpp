#include <string>
#include <vector>

using namespace std;
//erase를 사용하지 않는 빠른 풀이법
int solution(int n, int m, vector<int> section) {
    int answer = 1;

    int pivot = section[0];
    for(const auto v : section){//section을 순회
        if(v < pivot + m)//section의 값이 pivot+m(페인트를 칠하는 범위)보다 작으면 continue
            continue;
        else{//section의 값이 pivot+m보다 크면 한번 더 칠해야 하므로 해당 위치를 pivot으로 설정하고 answer++;
            pivot = v;
            answer++;
        }
    }

    return answer;
}