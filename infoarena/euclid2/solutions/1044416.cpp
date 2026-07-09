#include <iostream>
#include <cstdio>

using namespace std;


int gcd(long long x, long long y){

  while(y){

    int r = x%y;
    x = y;
    y =r;

  }
  return x;
}

int n;
int main(){

  freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  scanf("%d",&n);
  for(int i = 0; i < n ; i++){

    long long x,y;
    scanf("%lld %lld",&x,&y);
    cout << gcd(x,y) << endl;
  }
  return 0;
}