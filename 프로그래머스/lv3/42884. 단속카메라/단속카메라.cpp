#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//시작점을 오름차순으로 정렬
//검색하는 시작점이 end point보다 크다면 answer++; end point = 해당 시작점의 끝 점;
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    int end_point = routes[0][1];
    for(int k=1;k<routes.size();k++){
        if(routes[k][0]>end_point){
            answer++;
            end_point=routes[k][1];
        }
        else if(routes[k][1]<end_point)
            end_point=routes[k][1];
    }
    return answer;
}