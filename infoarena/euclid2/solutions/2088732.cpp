#include <iostream>

using namespace std;

int main () {
  int a, b, r, n, i;
  cin>>n;
  for ( i = 0; i < n; i++ ) {
    cin>>a>>b;
    while ( b ) {
      r = a % b;
      a = b;
      b = r;
    }
    cout<<a<<"\n";
  }
  return 0;
}
