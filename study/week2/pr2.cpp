#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 2001
#define FOR(X,s,t) for(int X=(s);X<=(t);X++)

int L,K;
char a[MAX];
int cost[26];

int dp[MAX+1][MAX+1];

void reset_dp() {
  FOR(i,0,MAX)
    FOR(j,0,MAX) 
    dp[i][j] = 0;
}

void print_dp(int M,int N) {
  FOR(i,1,M) {
  FOR(j,1,N) {
    printf("%7d ", dp[i][j]);
  }
  cout << endl;
  }
}


void go() {
  reset_dp();
  
  cin >> L >> K;

  FOR(i,1,L) cin >> a[i];
  
  int x,y;
  FOR(i,0,K-1) {
    cin >> x >> y;
    cost[i] = (x>y)?y:x;
  }

  FOR(k,0,L-1)
    for (int j = k+1,i=1; i <= (L-k); j++,i++) {
      if (i==j) { dp[i][j] = 0; continue; }
      int mincost;
      // 1. dp[i-1][j-1]      
      if ( a[i] == a[j] ) {
        dp[i][j] = dp[i+1][j-1];
      }
      // 2. dp[i][j-1]
      mincost = dp[i][j-1]+cost[a[j]-'a'];
      if (dp[i][j] > mincost) dp[i][j] = mincost;
      
      // 3. dp[i-1][j]
      mincost = dp[i+1][j]+cost[a[i]-'a'];
      if (dp[i][j] > mincost) dp[i][j] = mincost;
      
    }

  cout << dp[1][L] << endl;
  
  
}

int main()
{
  int test_case;
  int T;
  cin >> T;
	
  for(test_case = 1; test_case <= T; ++test_case) {
    go();	       
  }
  
  return 0;
}
