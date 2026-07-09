#include <stdio.h>
#include <fstream>
using namespace std;
int cmmdc(int a,int b);
int main()
{
    int t,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(;t;--t){
    f>>a;
    f>>b;
    g<<cmmdc(a,b);
    g<<'\n';
    }
    return 0;
}
int cmmdc(int a,int b)
{
   while(a!=b){
      if(a>b)
         a=a-b;
      else
         b=b-a;
   }
   return a;
}
