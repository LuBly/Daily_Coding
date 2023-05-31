#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
//1. 속한 노래가 많이 재생된 장르를 먼저 수록
//2. 장르 내에서 많이 재생된 노래를 먼저 수록
//3. 장르 내에서 재생횟수가 같은 노래 중에서는 고유번호가 낮은 노래를 먼저 수록
//map->장르>재생횟수>고유번호
bool cmp(pair<string,int> a, pair<string,int> b){
    return a.second>b.second;
}
bool cmp2(pair<int,int> a, pair<int,int> b){//{재생 횟수, idx}
    if(a.first==b.first)
        return a.second<b.second;
    else
        return a.first>b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre;//장르 이름, 총 합
    for(int k=0;k<genres.size();k++)//최대 10,000 
        genre[genres[k]]+=plays[k];
    //장르 총 합 기준으로 정렬
    //map을 vector로 변환 -> vector 정렬
    vector<pair<string, int>> gen(genre.begin(),genre.end());
    //1. 속한 노래가 많이 재생된 장르를 먼저 수록
    //-> 재생 순으로 장르 정렬
    sort(gen.begin(),gen.end(),cmp);
    
    for(auto name : gen){//최대 100개
        //장르 이름에 해당하는 plays 와 idx 저장
        vector<pair<int, int>> data;//play수와 idx 저장
        for(int idx=0;idx<genres.size();idx++){
            if(genres[idx]==name.first){
                data.push_back({plays[idx],idx});
            }
        }
        sort(data.begin(),data.end(),cmp2);
        if(data.size()==1){//장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
            answer.push_back(data[0].second);
            continue;
        }
        answer.push_back(data[0].second);
        answer.push_back(data[1].second);
    }
    
    return answer;
}