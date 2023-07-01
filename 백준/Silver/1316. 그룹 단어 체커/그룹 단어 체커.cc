//[Baekjoon C++] DFS와 BFS [dfs bfs]
#include <iostream>
#include <map>
using namespace std;


bool check(string input, bool is_visit[]){
    char cur = input[0];
    is_visit[cur-'a']=true;
    for(int k=1;k<input.size();k++){
        if(input[k]!=cur){//다른 문자가 나타났을 때, 같은 문자는 따로 체크x
            if(is_visit[input[k]-'a'])//이미 방문한 문자라면 false 
               return false; 
            else{
                cur=input[k];
                is_visit[cur-'a']=true;
            }
        }
    }
    return true;
}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int cnt;
    cin>>cnt;
    int answer=0;
    for(int k=0;k<cnt;k++){
        string input;
        cin>>input;
        bool is_visit[26]={false,};
        if(check(input, is_visit))
            answer++;
    }
    cout<<answer;
}