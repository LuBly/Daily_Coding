//[Programmers C++] 당구 연습
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    //y축 대칭, x축 대칭 체크하고 min값 계산
    //A공을 대칭이동
    //흰색이 검정 기준 왼쪽이라면 왼쪽 벽 기준 대칭, 흰색이 검정 기준 오른쪽이라면 오른쪽 벽 기준 대칭
    //흰색이 검정 기준 위쪽이라면 위쪽 벽 기준 대칭, 흰색이 검정 기준 아래쪽이라면 아래쪽 벽 기준 대칭
    for(int k=0;k<balls.size();k++){
        int len,a,b;//len 직선 길이, (a,b) 대칭 이동 후의 좌표간 거리
        if(startX==balls[k][0]){
            a=abs(startY-balls[k][1]);
            b=2*min(m-startX,startX);
            if(startY > balls[k][1]) len = len = pow(a + 2*(n - startY) ,2);
            else len = pow(a + 2*startY,2);
        }
        else if(startY==balls[k][1]){
            a = abs(startX - balls[k][0]);
            b = 2 * min(n - startY, startY);
            if (startX > balls[k][0]) len = pow(a + 2*(m - startX),2);
            else len = pow(a + 2*startX,2);
        }
        else{
            a = min(startX + balls[k][0], 2*m - startX - balls[k][0]);
            b = abs(startY - balls[k][1]);
            len = pow(a,2) + pow(b,2);
            a = min(startY + balls[k][1], 2*n - startY - balls[k][1]);
            b = abs(startX - balls[k][0]);
        }
        int cmp = pow(a,2)+pow(b,2);
        len = min(len,cmp);
        answer.push_back(len);
    }
    return answer;
}