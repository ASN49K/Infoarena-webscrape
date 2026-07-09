#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
 while(a!=b)
  if(a>b)
   a-=b;
  else
   b-=a;
  return a;
}
int main()
{   int T,a,b,i;
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    f>>T;
    for(i=1;i<=T;i++)
    {
     f>>a>>b;
     o<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
