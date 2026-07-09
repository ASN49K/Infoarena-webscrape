#include<fstream>
using namespace std;
long cmmdc( long a, long b)
{
     long r;
     r=a%b;
     while(r!=0)
     {
                a=b;
                b=r;
                r=a%b;}
     return b;}
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
