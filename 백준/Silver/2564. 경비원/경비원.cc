#include <iostream>
using namespace std;
int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    int s;
    cin >> s;
    int ss[s];
    for (int i = 0; i < s; i++)
    {
        int a, b;
        cin >> a >> b;
        switch (a)
        {
        case 1:
            ss[i] = b;
            break;
        case 2:
            ss[i] = 2 * r + c - b;
            break;
        case 3:
            ss[i] = 2 * (r + c) - b;
            break;
        case 4:
            ss[i] = r + b;
            break;
        }
    }
    int x, y;
    int xy = 0;
    cin >> x >> y;
    switch (x)
    {
    case 1:
        xy = y;
        break;
    case 2:
        xy = 2 * r + c - y;
        break;
    case 3:
        xy = 2 * (r + c) - y;
        break;
    case 4:
        xy = r + y;
        break;
    }
    int ans = 0;
    for (int i = 0; i < s; i++)
    {
        int temp = abs(xy - ss[i]);
        ans += temp < r + c ? temp : 2 * (r + c) - temp;
    }
    cout << ans;
}