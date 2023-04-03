#include <vector>
#include <queue>
using namespace std;

bool map[101][101]={false,};
bool is_visited[101][101]={false,};
int path[101][101]={0,};

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int width,length;

void BFS(int sty, int stx){
    queue<pair<int,int>> q;
    is_visited[sty][stx]=true;
    q.push(make_pair(sty,stx));
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int ny=y+dy[k];
            int nx=x+dx[k];
            if(ny>=length||nx>=width||ny<0||nx<0) continue;
            if(map[ny][nx]&&!is_visited[ny][nx]){
                path[ny][nx]=path[y][x]+1;
                is_visited[ny][nx]=true;
                q.push(make_pair(ny,nx));
            }
        }
    }
    
}

int solution(vector<vector<int> > maps)
{
    length = maps.size();//세로
    width = maps[0].size();//가로
    
    for(int a=0;a<length;a++){
        for(int b=0;b<width;b++){
            map[a][b]=maps[a][b];
        }
    }
    BFS(0,0);
    int answer = path[length-1][width-1]>0?path[length-1][width-1]+1:-1;
    return answer;
}