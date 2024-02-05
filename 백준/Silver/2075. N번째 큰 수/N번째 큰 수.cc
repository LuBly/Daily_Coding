//[Baekjoon C++] N번째 큰 수 [정렬]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
5 7 9 12 15
6 8 11 13 19
10 16 21 26 31


그냥 전부 입력받아서 sort하면 안되나?
*/
// 각 줄별로 sorting
// 
int arr[2250010];
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n * n);
    cout << arr[n * n - n] << endl;
}