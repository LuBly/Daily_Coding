//[Baekjoon C++] 문자열 폭발 [스택]
#include <iostream>
#include <string>
using namespace std;
// stack => FILO
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string input, boom, tmp="";
    cin>>input>>boom;

    // 앞에서 부터 temp를 채워넣기
    // temp를 채워 넣다가 뒤에서부터 boom문자열과 길이가 같아질 경우 boom 길이만큼 삭제
    for(int k = 0; k < input.size(); k++){
        tmp+=input[k];
        // tmp 문자열의 끝이 boom의 끝과 같다면 
        // boom 문자열만큼 tmp 문자열 체크
        if(tmp.back()==boom.back()){
            //현재 체크할 문자열이 boom 문자열보다 작으면 터질일은 없으니까 패스
            if(tmp.size()<boom.size()) continue;
            bool isBoom = true;
            for(int idx = 0; idx < boom.size(); idx++){
                if(tmp[tmp.size() - boom.size()+idx] != boom[idx]){
                    isBoom = false;
                    break;
                }
            }
            if(isBoom){
                for(int idx = 0; idx < boom.size(); idx++){
                    tmp.pop_back();
                }
            }
        }
    }

    if(tmp.empty()) cout<<"FRULA";
    else cout<<tmp;
}