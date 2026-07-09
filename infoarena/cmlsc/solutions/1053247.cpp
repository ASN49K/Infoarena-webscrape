#include <iostream>
#include <fstream>

using namespace std;

int maxim(int a, int b)
{
    if(a>b) return a;
    return b;
}

int main()
{
    int n, m, k=0, i, a[1024], b[1024], v[1024][1024], rez[1024];

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;cout<<n<<m;
    for(i=1; i<=n; i++)
       {

        f>>a[i];cout<<a[i]<<' ';}
    for(i=1; i<=m; i++)
        f>>b[i];
    int j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
    {
        if(a[i] == b[j])
            v[i][j] = 1 + v[i-1][j-1];

        else v[i][j] = maxim(v[i-1][j], v[i][j-1]);
    }

    i=n;
    j=m;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            k++;
            rez[k] = a[i];
            i--;
            j--;
        }
        else if(v[i-1][j] < v[i][j-1]) j--;
        else i--;
    }
    g<<k<<"\n";
    for(i=k; i; i--)
        g<<rez[i]<<' ';

    return 0;
}
