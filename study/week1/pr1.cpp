/* Original Source Reference : acmicpc.com
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int INF = 987654321;
 
vector<int> gap;
int memo[100][10][10][10];
int n;
 
int dp(int pos, int a, int b, int c) {
    if (pos == n) return 0;
    int& ret = memo[pos][a][b][c];
    if (ret != -1) return ret;
    if (a == 0) return ret = dp(pos + 1, b, c, gap[pos + 3]);
    ret = INF;
    for (int k = 1; k <= 3; ++k)
        for (int i = -3; i <= 3; ++i) {
            if (i == 0) continue;
            int nexta = a, nextb = b, nextc = c;
            switch (k) {
            case 3: nextc = (nextc + i + 10) % 10;
            case 2: nextb = (nextb + i + 10) % 10;
            case 1: nexta = (nexta + i + 10) % 10;
            }
            ret = min(ret, dp(pos, nexta, nextb, nextc) + 1);
        }
    return ret;
}
 
int main() {
    cin >> n;
    string a, b;
    cin >> a >> b;
    gap = vector<int>(n + 3);
    for (int i = 0; i < n; ++i)
        gap[i] = (a[i] - b[i] + 10) % 10;
     
    memset(memo, -1, sizeof(memo));
    cout << dp(0, gap[0], gap[1], gap[2]) << endl;
 
}
