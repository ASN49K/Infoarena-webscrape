#include<fstream>
using namespace std;
long cmmdc( long a, long b)
{
     if(b==0)
     return a;
     else
     return cmmdc(b,a%b);}
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
