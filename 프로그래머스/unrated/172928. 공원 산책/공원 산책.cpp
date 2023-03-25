#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int st_x,st_y;
    int height = park.size();
    int length = park[0].size();
    
    for(int a=0;a<height;a++){ //시작 지점 찾기
        for(int b=0;b<length;b++){
            if(park[a][b]=='S'){
                st_y = a;
                st_x = b;
            }
        }
    }
    //cout<<"start: "<<st_y<<" "<<st_x<<endl;
    
    int dest_x=st_x,dest_y=st_y;//각 회차별 스타트 지점 셋팅.
    for(int k=0;k<routes.size();k++){ // route읽으면서 진행
        char op = routes[k][0];//E : x++, W : x--, N : y--, S : y++
        int n = routes[k][2]-'0';
        bool is_possible = true;
        dest_x=st_x; dest_y=st_y;
        
        if(op=='E') {
            dest_x=st_x+n;
            if(dest_x<length){//x축 체크
                for(int a=st_x;a<=dest_x;a++){
                    if(park[st_y][a]=='X') {//중간에 장애물을 만난다면 이동 x
                        is_possible = false;
                        break;
                    }
                }
            }
            else is_possible=false;
        }
        
        else if(op=='W') {
            dest_x=st_x-n;
            if(dest_x>=0){//x축 체크
                for(int a=dest_x;a<=st_x;a++){
                    if(park[st_y][a]=='X') {
                        is_possible = false;
                        break;
                    }
                }
            }
            else is_possible = false;
        }
        
        else if(op=='N') {
            dest_y=st_y-n;
            if(dest_y>=0){//y축 체크
                for(int a=dest_y;a<=st_y;a++){
                    if(park[a][st_x]=='X'){
                        is_possible = false;
                        break;
                    }
                }
            }
            else is_possible = false;
        }
        else {//op=='S'
            dest_y=st_y+n;
            if(dest_y<height){//y축 체크
                for(int a=st_y;a<=dest_y;a++){
                    if(park[a][st_x]=='X') {//중간에 장애물을 만난다면 이동 x
                        is_possible = false;
                        break;
                    }
                }
            }
            else is_possible = false;
        }
        if(is_possible) {//아무것도 없으면 이동
            st_x=dest_x; st_y=dest_y;
        }
        cout<<st_y<<" "<<st_x<<endl;
    }
    answer.push_back(st_y);
    answer.push_back(st_x);
    return answer;
}