#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 1000

#define ALL(X,s,t) for(int X=(s);X<=(t);X++) 
#define ALL0(X,Y) ALL(X,0,Y)
#define ALL1(X,Y) ALL(X,1,Y)



int N;
int a[MAX];
int dp[MAX];

int main(int argc, char *argv[])
{
  cin >> N;
  //read
  ALL1(i,N) cin >> a[i];

  
  //go
  ALL1(i,N) {
    ALL(j,1,i) {
      if(a[j] < a[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
  }

  int max = -1;
  ALL1(i,N) {
    if ( max < dp[i] ) {
      max = dp[i];
    }
  }
  cout << max << endl;
  return 0;
}
