//[Baekjoon C++] 단어 뒤집기 [구현]
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//입력받은 값을 stack에 저장 하고 이를 출력?
// <>내부의 단어들은 그대로 출력
// 그냥 단어들은 띄어쓰기를 기준으로 거꾸로 출력
// < ~~ > 도 전부 출력해야함. 
// 조건을 어떻게 걸 것인가?
void reverse(string tmp){
    for(int k=tmp.size()-1;k>=0;k--){
        cout<<tmp[k];
    }
}
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string input;
    getline(cin,input);
    bool is_bracket = false;
    vector<string> split_str;
    string tmp = "";
    //자르는 기준 <,>, ' '
    for(int k=0;k<input.size();k++){
        if(input[k]=='<'){
            if(tmp.size()>0){
                reverse(tmp);
                tmp="";
            }
            while(input[k]!='>'){
                cout<<input[k++];
            }
            cout<<input[k];
            continue;
        }

        if(input[k]==' '){
            if(tmp.size()>0){
                reverse(tmp);
                tmp="";
            }
            cout<<input[k];
            continue;
        }
        
        if((input[k]>='a'&&input[k]<='z')||(input[k]>='0'&&input[k]<='9'))
            tmp+=input[k];
    }
    if(tmp.size()>0){
        reverse(tmp);
    }
}