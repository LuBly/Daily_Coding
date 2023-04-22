#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, max_height = triangle.size()-1;
    
    for(int k=1;k<triangle.size();k++){
        for(int j=0;j<triangle[k].size();j++){
            if(j>0&&j<triangle[k-1].size())
                triangle[k][j]+=max(triangle[k-1][j-1],triangle[k-1][j]);
            else if(j==0)
                triangle[k][j]+=triangle[k-1][j];
            else 
                triangle[k][j]+=triangle[k-1][j-1];
        }
    }
    
    for(int j=0;j<triangle[max_height].size();j++){
        answer = (answer>triangle[max_height][j]) ? answer : triangle[max_height][j]; //최대값 계산
    }
    
    return answer;
}