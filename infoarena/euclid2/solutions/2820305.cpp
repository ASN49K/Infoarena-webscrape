#include <iostream>
#include <fstream>

using namespace std;
int euclid(int a, int b){
  if(!b){
    return a;
  }
  return euclid(b, a%b);
}
int main()
{
  ifstream cinn("euclid2.in");
  ofstream coutt("euclid2.out");
  int n, a, b;
  cinn>>n;
  while(n){
      cinn>>a>>b;
      coutt<<euclid(a,b)<<endl;
      n--;
  }
  return 0;
}
