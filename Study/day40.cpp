#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    map<string,set<string>> report_data;
    map<string,int> id_idx;
    
    for(int c=0;c<id_list.size();c++){
        id_idx[id_list[c]]=c;
    }
    
    for(int a=0;a<report.size();a++){
        bool is_reported = false;
        string from="";//신고당한 사람
        string to="";//신고한 사람
        for(int b=0;b<report[a].size();b++){
            if(report[a][b]==' ') {
                is_reported = true;
                continue;
            }
            if(is_reported) to+=report[a][b];
            if(!is_reported) from+=report[a][b];
        }
        report_data[to].insert(from);
    }
    
    for(auto iter : report_data){
        if(iter.second.size()>=k){//이용 정지의 경우
            for(auto in_iter : iter.second){
                answer[id_idx[in_iter]]++;
            }
        }
    }
    
    return answer;
}