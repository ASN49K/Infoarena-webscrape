#include <iostream>
#include <fstream>

using namespace std;

int  gcd(int  a , int b)
{
    if (a==b){ return a;}
while (a!=b){ return a;}
{
    if (a>b){ return gcd(a%b,b); }
    else {
        return gcd(a,b%a);
    }
}

}
int main()
{

  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int t;
  int a;
  int b;
  f>>t;

for ( int i=1; i<= t; i++)
  {
f>>a>>b;
      g << gcd(a,b) << endl;
  }
}
