#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string makeCode(string m){
    for(int k=0;k<m.size();k++){
        if(m[k]=='#') {
            char tmp = m[k-1];
            string edit = "";
            tmp = tolower(tmp);
            edit+=tmp;
            m.replace(k-1,2,edit);
        }     
    }
    return m;
}

bool cmp(pair<int,string>a, pair<int,string>b){
    return a.first>b.first;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    //1. 시간계산
    //2. 시간만큼 악보 vector에 입력_시간이 m.size()보다 짧으면 패스
    //3. 악보 vector에서 m 있는지 check
    //+. #이 붙어있는 코드들을 소문자로 변형해서 check해야한다.
    string music_Code="";
    string check = makeCode(m);
    vector<pair<int,string>> correct;
    for(int k=0;k<musicinfos.size();k++){
        //h_st: 시작 시간(hour), h_end: 끝 시간(hour) h_end-h_st
        //m_st: 시작 시간(min), m_end: 끝 시간(min) m_end-m_st(음수라면 +60하고 h-1)
        auto idx = find(musicinfos[k].begin()+12,musicinfos[k].end(),',');
        //시간
        string h_st(musicinfos[k].begin(),musicinfos[k].begin()+2);
        string m_st(musicinfos[k].begin()+3,musicinfos[k].begin()+5);
        string h_end(musicinfos[k].begin()+6,musicinfos[k].begin()+8);
        string m_end(musicinfos[k].begin()+9,musicinfos[k].begin()+11);
        //음악 정보
        string music(musicinfos[k].begin()+12, idx);
        string code(idx+1,musicinfos[k].end());
        string codeEdit = makeCode(code);
        string musicinfo="";
        
        int hour = stoi(h_end)-stoi(h_st);
        int min = stoi(m_end)-stoi(m_st);
        if(min<0){
            min+=60;
            hour--;
        }
        int time = hour*60+min;
        if(time<check.size()) continue;
        else{//시간만큼 codeEdit을 복제
            int div = codeEdit.size();
            for(int k=0;k<time;k++){
                musicinfo+=codeEdit[k%div];
            }
            
            if(musicinfo.find(check) != string::npos){
                correct.push_back(make_pair(time,music));
            }
            else continue;
        }
    }
    if(correct.size()>1){
        stable_sort(correct.begin(),correct.end(),cmp);
    }
    if(correct.empty()){
        answer += "(None)";
        return answer;
    }
    answer += correct[0].second;
    return answer;
}