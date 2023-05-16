#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
// 조합 카운트를 세서 가장 큰거 out
// 2 3 4니까 2일때 한번 3일때 한번 4일때 한번으로 
map<string,int> cnt[11];
void comb(string menu, vector<char> tmp, int idx, int depth, int num){//조합가능한 경우의 수
    if(depth == tmp.size()){
        string result = "";
        for(int i = 0; i < tmp.size(); i++)
            result+=tmp[i];
        sort(result.begin(),result.end());//결과 값 순서 맞추기 WX == XW
        cnt[num][result]++;
        return;
    }
    else{
        for(int i = idx; i < menu.size(); i++){
            tmp[depth] = menu[i];
            comb(menu, tmp, i + 1, depth + 1, num);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<char,int> data;//메뉴, 주문 횟수 map
    
    for(int k=0;k<course.size();k++){//선택할 메뉴의 갯수
        int num = course[k];
        for(int j=0;j<orders.size();j++){
            string menu = orders[j];
            if(num>menu.size()) continue;//선택하는 메뉴구성의 숫자가 주문한 메뉴보다 크면 continue
            vector<char> tmp(num);
            comb(menu,tmp,0,0,num);
        }    
    }
    for(int k=0;k<course.size();k++){
        int idx = course[k];    
        int max = 0;
        vector<string> res;
        for(auto iter : cnt[idx]){//idx 중 가장 많이 나온 숫자
            if(iter.second > max)
                max = iter.second;
        }
        if(max<2) continue;//최소 2명 이상의 손님에게서 주문된 구성만 후보에 들어가므로 그 이하는 out
        for(auto iter : cnt[idx]){
            if(iter.second == max)//위에서 계산한 max값과 동일한 결과값을 가진 메뉴 조합 전부 res에 push
                res.push_back(iter.first);
        }
        for(auto iter : res)
            answer.push_back(iter);
    }
    sort(answer.begin(),answer.end());//결과값 정렬 
    return answer;
}