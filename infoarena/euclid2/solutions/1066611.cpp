#include<fstream>
using namespace std;
long cmmdc( long a, long b)
{
     if(a==b)
     return a;
     else
     if(a>b)
     return cmmdc(a-b,b);
     else
     return cmmdc(a,b-a);}
int main()
{
    long t,i,a,b;
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>t;
    for(i=1;i<=t;i++)
    {
                     f>>a>>b;
                     g<<cmmdc(a,b)<<endl;}
    return 0;}
