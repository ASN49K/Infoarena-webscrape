#include <iostream>
#include <fstream>

using namespace std;

int  gcd(int  a , int b)
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
