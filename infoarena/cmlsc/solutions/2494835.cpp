#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMax=1024;
int m, n, a[NMax], b[NMax], d[NMax][NMax], sir[NMax], bst;
int maxim(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int i,j;
    fin>>n>>m;

    for(i=1;i<=m;++i)
        fin>>a[i];

    for(i=1;i<=n;++i)
        fin>>b[i];

    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
    {
        if(a[i]==b[j])
            d[i][j]=1+d[i-1][j-1];
        else
            d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    }

    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;

    fout<<bst<<"\n";
    for (i = bst; i; --i)
        fout<<sir[i]<<" ";
    return 0;
}
