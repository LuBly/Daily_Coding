//[Programmers C++] 행렬의 곱셈
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int a = 0; a < arr1.size(); a++){
        vector<int> row;
        for(int b = 0; b < arr2[0].size(); b++){
            int row_tmp = 0;
            for(int c = 0; c < arr2.size(); c++){
                row_tmp += arr1[a][c]*arr2[c][b];
            }
            row.push_back(row_tmp);    
        }
        answer.push_back(row);
    }
    
    return answer;
}
