#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000007
#define MAX 5001

int T,M,C;
int coin[101];
int dp[MAX];

int go()
{

  
    memset(dp, 0, sizeof(dp));
 
    // Base case (If given value is 0)
    dp[0] = 1;
 
    for(int i=0; i<C; i++) {
      for(int j=coin[i]; j<=M; j++) {
            dp[j] += dp[j-coin[i]];
            dp[j] %= MOD;
      }
    }
    
 
    return dp[M];
}

int main(int argc, char *argv[])
{
  cin >> T ;
  for (int t = 1; t <= T; t++) {
    cin >> M >> C;
    // read coin value
    for (int j=0; j < C; j++){
      cin >> coin[j];
    }

    // Compute DP table
    cout << go() << endl;
    
  }

  
  
  return 0;
}
