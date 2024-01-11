#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
sortBy를 기준으로 오름차순 정렬을 먼저 수행
정렬된 친구 중에 val_ext 보다 작은 친구들만 따로 answer에 저장
*/
int sortIdx;

bool cmp(vector<int> a, vector<int> b){
    return a[sortIdx] < b[sortIdx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    map<string, int> idx;    
    idx["code"] = 0; idx["date"] = 1; idx["maximum"] = 2; idx["remain"] = 3;
    
    vector<vector<int>> answer;
    sortIdx = idx[sort_by];
    sort(data.begin(), data.end(), cmp);
    
    for(int k = 0; k < data.size(); k++){
        if(data[k][idx[ext]] < val_ext){
            answer.push_back(data[k]);
        }
    }
    return answer;
}