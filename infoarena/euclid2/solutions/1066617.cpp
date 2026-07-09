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
    long t,a,b;
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>t;
    while(t>0)
    {
                     f>>a>>b;
                     g<<cmmdc(a,b)<<endl;
                     t--;}
    return 0;}
