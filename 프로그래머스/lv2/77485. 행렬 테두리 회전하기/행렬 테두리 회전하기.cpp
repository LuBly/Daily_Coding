#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int arr[101][101];
    int side[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            arr[i][j] = ((i - 1) * columns) + j;

    for (int i = 0; i < queries.size(); i++)
    {
        int dir = 0;
        int minNum = 10010;
        int y = queries[i][0];
        int x = queries[i][1];
        int firstNum = arr[y][x];

        while (y != queries[i][0] || x != queries[i][1] + 1)
        {
            if(y==queries[i][2]&&x==queries[i][1])
                dir++;
            else if(y==queries[i][2]&&x==queries[i][3])
                dir++;
            else if(y==queries[i][0]&&x==queries[i][3])
                dir++;
            
            arr[y][x] = arr[y + side[dir][0]][x + side[dir][1]];
            y += side[dir][0];
            x += side[dir][1];
            minNum = min(minNum, arr[y][x]);
        }
        arr[y][x] = firstNum;
        minNum = min(minNum, arr[y][x]);
        answer.push_back(minNum);
    }

    return answer;
}