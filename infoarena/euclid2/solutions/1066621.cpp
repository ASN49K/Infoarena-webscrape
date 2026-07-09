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
    long t,a,b;
    ifstream f("euclid2.in",ios::in);
    ofstream g("euclid2.out",ios::out);
    f>>t;
    while(t>0)
    {
                     f>>a>>b;
                     g<<cmmdc(a,b)<<endl;
                     t--;}
    return 0;}
