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
  while(n){
    in>>a>>b;
    out<<euclid(a,b)<<"\n";
    n--;
  }
  return 0;
}
