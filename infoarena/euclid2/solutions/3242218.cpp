#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  int n, c; cin>>n;
  int a, b;
  while(n--){
    cin>>a>>b;
    while(a%b > 0){
      c = a % b;
      a = b;
      b = c;
    }
    cout<<b<<"\n";
  }
}
