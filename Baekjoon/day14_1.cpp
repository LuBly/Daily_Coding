#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
	long long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


long long solution(int w,int h) {
    long long answer = 1;
    long long g = gcd((long long)w,(long long)h);
    long long x = (long long)w/g;
    long long y = (long long)h/g;
    long long m = x+y-1;
    
    answer = (long long)w*(long long)h - ((long long)w/x)*m;
    
    
    return answer;
}