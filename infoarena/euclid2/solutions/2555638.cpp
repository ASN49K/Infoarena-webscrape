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
   if(!b) return a;
   return cmmdc(b,a%b);
}
