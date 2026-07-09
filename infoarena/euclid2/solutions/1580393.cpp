#include <iostream>
#include <fstream>
using namespace std;


int main()
{int a,b,n,r;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>n;
  while(n>0)
  {  f>>a;
     f>>b;
     while(b!=0)
       {r=a%b;
        a=b;
        b=r;}
     g<<a<<"\n";
     n--;
  }
    return 0;
}
