#include <string>
#include <vector>
#include <iostream>
using namespace std;
//stack형식을 사용해서 first in last out으로 문제를 해결하려함
int solution(vector<int> order) {
    int answer = 0;
    vector<int> tmp;//보조 컨테이너    
    int out;//answer을 커서 역할로 사용
    for(int k=1;k<=order.size();k++){//컨베이어 벨트에서 상자 하나씩 나오게함
        out=order[answer];
        //cout<<"k: "<<k<<" out: "<<out;
        if(out==k){//지금 들어온 상자가 order에 맞는 상자라면 answer++
            //cout<<" out origBelt";
            answer++;
        }
        else if(!tmp.empty()&&out==tmp.back()){
            //cout<<" out tmpBelt";
            tmp.pop_back();
            k--;//tmp벨트에서 나갈 수 있는지만 체크한 경우로, 이 때 상자는 처리하지 않았기 때문에 -1을 통해 다시 체크하도록 한다.
            answer++;
        }
        else{//순서에 맞지않는 상자가 나온다면 임시 벨트에 in
            //cout<<" insert tmpBelt";
            tmp.push_back(k);
        }
        //cout<<endl;
    }
    
    while(!tmp.empty()){
        out=order[answer];
        if(out==tmp.back()){
            //임시 벨트가 비어있지 않고, 임시 벨트의 마지막에 order에 맞는 상자가 있다면 거기서 꺼내기
            //cout<<" out tmpBelt";
            tmp.pop_back();
            answer++;
            continue;
        }
        else break;
    }
    return answer;
}