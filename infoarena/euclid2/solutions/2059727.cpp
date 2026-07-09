#include <iostream>
#include <fstream>

using namespace std;

long  gcd(long  a , long b)
{
while  (a!=b)
{
    if (a>b){
        a=a%b;
    }
    {
      if (b>a) { b=b%a; }
    }
}
return a;

}
int main()
{

  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  long t;
  long a;
  long b;
  f>>t;

for ( long i=1; i<= t; i++)
  {
f>>a>>b;
      g << gcd(a,b) << endl;
  }
}
