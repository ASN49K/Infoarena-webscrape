#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int v[257], poz[257], a[1024], MAX;
int main()
{int n, m, i, x, ant;
    f>>m>>n;
    for (i=1; i<=m; i++)
    {
        f>>x;
        v[x]=1;
        poz[x]=i;
    }
    ant=n;
    for (i=1; i<=n; i++){
        f>>x;
        if (v[x]==1 && poz[x]>=i) a[++MAX]=x;
    }
    g <<MAX<<"\n";
    for (i=1; i<=MAX; i++)
        g <<a[i]<<" ";
    return 0;
}
