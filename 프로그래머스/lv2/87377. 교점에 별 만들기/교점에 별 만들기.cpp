#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int,int>> star;//교점의 좌표를 저장할 vector
    //각 직선들을 두개씩 비교하며 교점 check
    for(int k=0;k<line.size()-1;k++){//앞서 들어오는 line Ax+By+E=0
        for(int j=k+1;j<line.size();j++){//비교할 line Cx+Dy+F=0
            long long A = line[k][0], B = line[k][1], E = line[k][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];
            long long d = (A*D-B*C);
            if(d==0) continue;
            long long x = (B*F-E*D);
            long long y = (E*C-A*F);
            
            if(x%d==0&&y%d==0) star.push_back(make_pair(x/d,y/d));
        }
    }
    
    auto max_X = *max_element(star.begin(),star.end());
    auto max_Y = *max_element(star.begin(),star.end(),cmp);
    auto min_X = *min_element(star.begin(),star.end());
    auto min_Y = *min_element(star.begin(),star.end(),cmp);
    
    int maxX=max_X.first, minX=min_X.first;
    int maxY=max_Y.second, minY=min_Y.second;
    /*
    for(auto iter:star){
        cout<<iter.first<<" "<<iter.second<<endl;
    }
    */  
    for(int k=maxY; k>=minY;k--){
        string tmp="";
        for(int j=minX;j<=maxX;j++){
            if(find(star.begin(),star.end(),make_pair(j,k))!=star.end()) tmp+='*';
            else tmp+='.';
        }
        answer.push_back(tmp);
    }
    
    
    return answer;
    
}