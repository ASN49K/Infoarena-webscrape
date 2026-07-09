#include<fstream>
using namespace std;
long cmmdc( long a, long b)
{
     long r;
     while(b!=0)
     {
                r=a;
                a=b;
                b=r%b;}
     return a;}
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
