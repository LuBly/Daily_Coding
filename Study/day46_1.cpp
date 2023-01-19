//[Programmers C++] 오픈채팅방
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,string> > record_data;
    map<string,string> user_Id;
    
    for(int a=0;a<record.size();a++){
        int cur=0;
        string tmp="";
        string uid="";
        string status = "";
        for(int b=0;b<record[a].size();b++){
            if(record[a][b]!=' ') tmp+=record[a][b];
            else{//띄어쓰기일 때
                if(cur==0){
                    status+=tmp;
                    cur++;
                    tmp="";
                }
                else if(cur==1){
                    uid+=tmp;
                    cur++;
                    tmp="";
                }
            }
            if(b==record[a].size()-1 && cur==1){
                uid+=tmp;
                tmp="";
            }
            
        }
        if(cur==2) user_Id[uid]=tmp;
        record_data.push_back(make_pair(status,uid));
    }
    for(int k=0;k<record_data.size();k++){
        if(record_data[k].first.compare("Change")==0) continue;
        string result_str="";
        result_str+=user_Id[record_data[k].second];
        if(record_data[k].first.compare("Enter")==0) {
            result_str+="님이 들어왔습니다.";
            answer.push_back(result_str);
            continue;
        }
        if(record_data[k].first.compare("Leave")==0) {
            result_str+="님이 나갔습니다.";
            answer.push_back(result_str);
            continue;
        }
        
    }
    /*
    for(auto iter:user_Id){
        cout<<"uid: "<<iter.first<<" name: "<<iter.second<<endl;
    }
    */
    return answer;
}