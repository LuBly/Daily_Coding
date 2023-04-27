#include <string>
#include <vector>

using namespace std;
//알파벳을 위아래로 이동하면서 체크하는 최적값
int alpha_to_move[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};

int solution(string name) {
    int answer = 0;
    int length = name.size();
    int min_move = length-1;
    for(int k=0;k<length;k++){
        answer+=alpha_to_move[name[k]-'A'];
        // 원점을 기준으로 k까지 탐색하고 다시 역방향으로 k+1까지 탐색했을때의 이동거리
        // 원점을 기준으로 역방향으로 k+1까지 탐색하고 다시 정방향으로 y까지 탐색했을 때의 이동 거리
        int nx = k+1;
        while(nx<length&&name[nx]=='A') nx++;
        min_move = min(min_move, k+length-nx+min(k,length-nx));
    }
    answer+=min_move;
    return answer;
}