//[Programmers C++] 소수 찾기
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool is_prime(int num){
    if(num<2) return false;
    for(int k=2;k*k<=num;k++){
        if(num%k==0) return false;
    }
    return true;
}



int solution(string numbers) {
    int answer = 0;
    vector<int> index_vec;
    map<int,bool> is_visit;
    for(int a=0; a<numbers.size();a++) index_vec.push_back(a);
    
    do{
        string tmp="";
        for(int b=0;b<index_vec.size();b++){
            int index=index_vec[b];
            tmp+=numbers[index];
            if(is_prime(stoi(tmp))&&is_visit[stoi(tmp)]==0){
                is_visit[stoi(tmp)]=true;
                answer++;
            }
        }
    }while(next_permutation(index_vec.begin(),index_vec.end()));
    
    return answer;
}