#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
    while(a!=b)
    if(a>b)
    a=a-b;
    else
    b=b-a;
    return a;}
int main()
{
    int n,a,b,i;
    ifstream f("euclid2.in", ios::in);
    ofstream g("euclid2.out", ios::out);
    f>>n;
    for(i=1;i<=n;i++)
    {f>>a>>b;
    if(cmmdc(a,b)==1)
    g<<0;
    else
    g<<cmmdc(a,b);}
    f.close();
    g.close();
    return 0;}
