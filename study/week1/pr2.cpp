#include <iostream>
#include <stdio.h>

using namespace std;

#define LL long long
#define MAX 100001
#define INF 1000000000000000001LL

LL num_tests, N,T,Q;
LL city[MAX];
LL query[1001];
LL dir[MAX];
LL stop_point[MAX];

enum { RIGHT=1, LEFT=2 };

int main(int argc, char *argv[])
{
  cin >> num_tests ;

  for (LL i = 1; i <= num_tests; i++) {
    cin >> N >> T >> Q;
    // read city, direction
    for (LL j=1; j <= N; j++) {
      cin >> city[j] >> dir[j];     
    }
    // read query index
    for (LL j=1; j <= Q; j++) {
      cin >> query[j];     
    }

    // go
    LL pivot=1, middle_position=INF;
    for (LL j = 1; j <= N+1; j++) {
      if ( (dir[j-1] != RIGHT && dir[j] == RIGHT) ){     //   j-1  j j+1 
        // update from pivot to j                        // <  <   >  >
        for (int k=pivot;k<=j-1;k++) {
          stop_point[k] = middle_position;
        }
        // reset 
        pivot = j;
        middle_position = INF;
      }                                                   
      else if ( (dir[j-1] == RIGHT && dir[j] == LEFT)) {  //    j-1  j  j+1
        middle_position = (city[j-1] + city[j] ) / 2;     //  >  >   <  <

        for (int k=pivot;k<=j-1;k++) {
          stop_point[k] = middle_position;
        }
        // reset 
        pivot = j;
      }
      else if (j==N+1){
        for (int k=pivot;k<=j-1;k++) {
          stop_point[k] = middle_position;
        }
      }
    }    
    // print query
    for (LL j=1; j <= Q; j++) {
      LL qu = query[j];
      LL sign = (dir[qu]==LEFT)?(-1):1;
      
      if (stop_point[qu] == INF) {
        cout << city[qu]+sign*T << " ";
      }
      else {
        LL diff = stop_point[qu] - city[qu];
        diff = (diff>0)?diff:(-diff); //abs
        if ( T >= diff ) cout << stop_point[qu] << " ";
        else             cout << city[qu]+sign*T << " "; 
      }
    }
    cout << endl;
  }
  return 0;
}
