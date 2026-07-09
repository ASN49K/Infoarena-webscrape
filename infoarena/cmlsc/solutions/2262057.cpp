#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n,x;
bool k[260];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>x;k[x]=1;
    }
    for(int i=1;i<=m;i++)
    {
        in>>x;
        if(k[x])
        {
            out<<x<<' ';
        }
    }
    return 0;
}
