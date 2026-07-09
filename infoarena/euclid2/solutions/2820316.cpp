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
  ifstream in("euclid2.in");
  ofstream out("euclid2.out");
  int n, a, b;
  in>>n;
  for(int i = n; i > 0; i++){
      in>>a>>b;
      out<<euclid(a,b)<<endl;
      n--;
  }
  return 0;
}
