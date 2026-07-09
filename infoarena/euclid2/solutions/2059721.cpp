#include <iostream>

using namespace std;

long  gcd(long  a , long b)
{
while  (a!=b)
{
    if (a>b){
        a=a-b;
    }
    {
      if (b>a) { b=b-a; }
    }
}
return a;

}
int main()
{

  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int n;
  f>>n;

for ( int i=1; i<= T; i++)
  {
f>>a>>b;
      g << gcd(a,b) << endl;
  }
}
