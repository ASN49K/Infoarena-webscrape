#include<fstream>
using namespace std;
ifstream f("euclid2.in", ios::in);
ofstream g("euclid2.out", ios::out);
int cmmdc( int a, int b)
{
    if(a>b)
    return cmmdc(a-b,b);
    else
    if(a<b)
    return cmmdc(a,b-a);
    else
    if(a==b)
    return a;}
int main()
{
    int a,n,b,i;
    f>>n;
    for(i=1;i<=n;i++)
    {
                     f>>a;
                     f>>b;
                     g<<cmmdc(a,b);}
    return 0;}
    
