#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a%2==0&&b%2==0)
        return 2*cmmdc(a/2,b/2);
    if(a%2==0)
        return cmmdc(a/2,b);
    if(b%2==0)
        return cmmdc(a,b/2);
    return cmmdc(min(a,b),max(a,b)-min(a,b));
}
int main()
{   int a,b,n;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
       fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }

    return 0;
}
