//[Programmers C++] 과일 장수
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int cur = 0;
    sort(score.rbegin(),score.rend());
    
    for(int k =0; k<score.size()/m; k++){
        answer += (score[cur+m-1]*m);
        cur+=m;
    }
   
    return answer;
}
