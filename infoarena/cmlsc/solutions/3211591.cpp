#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int frecv[257], fre[257];
int main()
{
    int m,n,x;
    in>>m>>n;
    int mini=257, maxi=0;
    for(int i=0; i<m; ++i)
    {
        in>>x;
        frecv[x]++;
        if(x<mini)
            mini=x;
        if(x>maxi)
            maxi=x;
    }
    for(int i=0; i<n; ++i)
    {
        in>>x;
        fre[x]++;
        if(x<mini)
            mini=x;
        if(x>maxi)
            maxi=x;
    }
    int length=0;
    for(int i=mini; i<=maxi; ++i)
    {
        if(frecv[i]>0 && fre[i]>0)
            ++length;
    }
    out<<length<<'\n';
    for(int i=mini; i<=maxi; ++i)
    {
        if(frecv[i]>0 && fre[i]>0)
            out<<i<<" ";
    }
    return 0;
}
