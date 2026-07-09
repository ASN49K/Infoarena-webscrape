#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,i,j=0,a;
    f>>n>>m;
    int x[257];
    for(i=1;i<=256;i++) x[i]=0;
    for(i=1;i<=n;i++)
    {f>>a;x[a]++;}
    for(i=1;i<=m;i++)
    {f>>a;if(x[a]==1) {x[a]++;j++;}}
    g<<j<<"\n";
    for(i=1;i<=256;i++) if(x[i]==2) g<<i<<" ";
    f.close();
    g.close();
    return 0;
}
