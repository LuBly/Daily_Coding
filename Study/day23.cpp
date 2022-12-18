#include <string>
#include <vector>
#include <iostream>
using namespace std;
int gcd(int a, int b){
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    int gcd_num;
    int lcm;
    
    for(int k=1;k<arr.size();k++){
        gcd_num = gcd(answer,arr[k]);
        lcm = answer*arr[k]/gcd_num;
        answer = lcm;
    }
    return answer;
}