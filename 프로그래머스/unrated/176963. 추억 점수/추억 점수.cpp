#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> name_Map;
    for(int k=0;k<name.size();k++){
        name_Map[name[k]]=yearning[k];
    }
    for(int p=0;p<photo.size();p++){
        int tmp=0;
        for(int q=0;q<photo[p].size();q++){
            string N = photo[p][q];
            tmp+=name_Map[N];
        }
        answer.push_back(tmp);
    }
    return answer;
}