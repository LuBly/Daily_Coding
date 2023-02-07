//[Programmers C++] 줄 서는 방법
/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    for(int k=1;k<=n;k++) answer.push_back(k);//if n = 3 -> answer [1,2,3]
    //answer.push_back(1); answer.push_back(3); answer.push_back(2);
    
    long long count = 1;
    do{
        if(count == k) break;
        count++;
    } while(next_permutation(answer.begin(),answer.end()));
    
    return answer;
}
*/
//시간초과 나는 코드

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> arr_vec;
    vector<long long> facDP;
    facDP.push_back(1); // 1 ! =1 facDP[n]=n+1!, fac[0]=1!, fac[1]=2!,
    for(int a=1;a<=n;a++) arr_vec.push_back(a);// arr_vec에 숫자 넣기 [1,2,3,4,........,n] 
    for(int k=2;k<n;k++){
        facDP.push_back(facDP[k-2]*k);
    }
    /*
    for(int j=0;j<facDP.size();j++){
        cout<<facDP[j]<<endl;
    }
    */
    
    while(n!=0){
        if(n==1){
            answer.push_back(arr_vec[0]);            
            break;
        }
        else{
            long long idx;
            if(k==0){
                if(n>2) {
                    k=facDP[n-1];
                    idx = (k-1)/facDP[n-2];
                }
                else idx = 1;
            }
            else idx = (k-1)/facDP[n-2];
            //cout<<k-1<<" n: "<<n<<" "<<facDP[n-2]<<" "<<idx<<" "<<arr_vec[idx]<<endl;
            k%=facDP[n-2];
            answer.push_back(arr_vec[idx]);
            arr_vec.erase(arr_vec.begin()+idx);
            n--;
        }
    }
    return answer;
}