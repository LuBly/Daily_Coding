#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    //처음부터 끝까지 보석종류-개수 를 map에 저장해놓고
    //투포인터를 사용
    //앞에서 map[보석종류]<1인 지점을 찾기
    //뒤에서 map[보석종류]<1인 지점을 찾기
    map<string,int> data;
    int start=0, end=0;
    int min_start=0, min_end=0;
    
    for(int k=0;k<gems.size();k++){
        string gem = gems[k];
        data[gem]++;
        if(data[gem]==1){//지금 들어온 보석이 처음 들어온 보석이라면 end포인트 갱신
            end = k;
            min_start=start;
            min_end=end;
        }
        //중복된 요소가 들어온 경우
        //시작지점부터 중복된 보석이 들어온 만큼 이동
        else{
            end = k;
            for(int j=start;j<k;j++){
                string chk = gems[j];
                //head쪽에 2개 이상 있는 경우 1개 제거
                if(data[chk]>1)
                    data[chk]--;
                else{
                    //1개만 있는 경우 해당 위치를 구간의 시작으로 잡고 갱신 종료
                    start=j;
                    if((end-start)<(min_end-min_start)){
                        min_start = start;
                        min_end = end;
                    }
                    break;
                }
            }
        }
    }
    
    
    
    answer.push_back(min_start+1);
    answer.push_back(min_end+1);
    
    return answer;
}