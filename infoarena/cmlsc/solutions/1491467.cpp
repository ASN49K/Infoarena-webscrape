#include <iostream>
#include <fstream>
using namespace std;
int v[1025];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int i,n,m,x,j=0;
    f>>n>>m;
    for(i=1;i<=n;i++){
        f>>x;
        v[x]++;
        j=max(j ,x);
    }
    for(i=1;i<=m;i++){
        f>>x;
        v[x]++;
        j=max(j ,x);
    }
    //j=max(m,n);
    for(i=1;i<=j;i++)
        if(v[i]==2)g<<i<<' ';

    return 0;
}
