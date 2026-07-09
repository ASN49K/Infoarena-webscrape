#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;
fstream fout("cmlsc.out", ios::out);

int v[1025][1025], a[1025], b[1025], sol[1025], n, m, sl;
int maxx(int a, int b)
{
    if(a>b) return a;
    return b;
}
void ReadData()
{
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    for (int i=1; i<=n; ++i)
        fin>>a[i];
    for (int i=1; i<=m; ++i)
        fin >> b[i];
    fin.close();
}
int main()
{
    ReadData();
    freopen("cmlsc.out","w",stdout);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=maxx(v[i][j-1], v[i-1][j]);

    cout<<v[n][m]<<endl;
    int t=0;
    while(n>0&&m>0)
    {
        if(a[n]==b[m])
        {
            sol[++t]=a[n];
            n--;m--;
        }
        else
            if(v[n][m-1]>v[n-1][m])
                m--;
            else
                n--;

    }
    for(int i=t;i>=1;i--)
        printf("%d ",sol[i]);

    return 0;
}
