#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[100],b[100],d[100][100],sir[100],best;

int maxim(int x,int y)
{
    return( (x>y) ? x : y);
}

int main()
{
    int i,j;
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(j=1;j<=n;j++)
        fin>>b[j];

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = maxim(d[i][j-1],d[i-1][j]);
    for(i=m,j=n;i;)
        if(a[i] == b[j])
            sir[++best] = a[i],--i,--j;
        else if(d[i-1][j] < d[i][j-1])
                --j;
        else --i;

    fout<<best<<endl;
    for(i=best;i;--i)
        fout<<sir[i]<<" ";
    return 0;

}
