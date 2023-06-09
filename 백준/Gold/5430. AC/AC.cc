//[Baekjoon C++] AC [구현]
#include <iostream>
#include <string>
#include <vector>
#include <deque> //idx로 관리하려했으나, 큰 숫자에서 뭔가 이유 모를 오류가 발생한다.
using namespace std;
//AC연산
//R => 뒤집기 -> 배열에 있는 숫자들의 순서를 뒤집는 함수
//D => 버리기 -> 첫번째 수를 버리는 함수. + 배열이 비어있는데 D를 사용하면 에러발생

deque<int> parse_int(string str){
    deque<int> result;
    string num="";
    for(int k=0;k<str.size();k++){
        if(str[k]=='['||str[k]==']') continue;
        if(str[k]==','){
            result.push_back(stoi(num));
            num="";
            continue;
        }
        num+=str[k];
    }
    if(num.size()>0) result.push_back(stoi(num));
    return result;
}
/*
vector<int> reverse(vector<int> data){
    vector<int> result;
    for(int k=data.size()-1;k>=0;k--){
        result.push_back(data[k]);
    }
    return result;
}
*/

void do_func(deque<int> data, string func){
    //출력할 data 가공
    bool is_reverse=false;
    bool error=false;
    for(int k =0;k<func.size();k++){
        if(func[k]=='R'){
            is_reverse = is_reverse ? false : true;//is_reverse가 true면 false로 false면 true로 변경
        }        
        else if(func[k]=='D'){
            if(!data.empty()){
                if(is_reverse) data.pop_back();//거꾸로인 상태라면 뒤에서 하나 빼주고
                else data.pop_front();//정순인 상태라면 앞에서 하나를 지워줌.
            }
            else{//data가 비어있는데 erase를 하려고 하는 경우 error를 출력하고 함수 종료
                cout<<"error"<<'\n';
                error=true;
                break;
            }
        }
    }
    if (!error) {
        cout << '[';
    }
    if (is_reverse && !data.empty()) {
        for (auto o = data.rbegin(); o != data.rend(); o++) {
            if (o == data.rend() - 1)
                cout << *o;
            else
            cout << *o << ',';
        }
    }
    else if (!is_reverse&&!data.empty()){
        for (auto o = data.begin(); o != data.end(); o++) {
            if (o == data.end() - 1)
                cout << *o;
            else
            cout << *o << ',';
        }
    }
    if(!error)
        cout <<"]\n";
}

int main(void){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int test_cnt;//테스트 케이스 개수 T
    cin>>test_cnt;
    for(int k=0;k<test_cnt;k++){
        string func;
        cin.ignore();
        cin>>func;//수행할 함수 입력받기
        int length;
        cin>>length;
        string nums;
        cin>>nums;
        deque<int> data = parse_int(nums);//[a,b,c,d] 형태의 문자열에서 a,b,c,d를 꺼내올 함수
        do_func(data,func);//함수 수행
    }
}
