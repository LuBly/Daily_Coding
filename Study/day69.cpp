//[Programmers C++] [3차] 파일명 정렬
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(tuple<string, string, string> v1, tuple<string, string, string> v2){
    if(strcmp(get<0>(v1).c_str(),get<0>(v2).c_str())==0){//두개가 같으면
        return stoi(get<1>(v1)) < stoi(get<1>(v2));
    }
    else return get<0>(v1) < get<0>(v2);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string,string,string>> data; //head, number, orig
    for(int a=0;a<files.size();a++){
        string head="";
        string number="";
        string orig="";
        int cur=0;
        int num_sz=0;
        for(int b=0;b<files[a].size();b++){
            if(files[a][b]>='0'&&files[a][b]<='9'&&cur==0&&num_sz<5) cur=1;
            if(((files[a][b]>='a'&&files[a][b]<='z')
                ||(files[a][b]>='A'&&files[a][b]<='Z')
                ||files[a][b]==' '
                ||files[a][b]=='.'
                ||files[a][b]=='-')
               &&cur==1) cur=2;
            
            orig+=files[a][b];
            if(cur==0) {
                if(files[a][b]>='A'&&files[a][b]<='Z'){ 
                    files[a][b]+=32;
                    head+=files[a][b];
                }
                else head+=files[a][b];
            }
            else if(cur==1) {
                number+=files[a][b];
                num_sz++;
            }
        }
        data.push_back(make_tuple(head,number,orig));
    }
    stable_sort(data.begin(),data.end(),cmp);
    for(auto iter : data){
        string tmp="";
        tmp+=get<2>(iter);
        answer.push_back(tmp);
        //cout << "head: "<<get<0>(iter)<<" num: "<<get<1>(iter)<<endl;
    }
    
    return answer;
}