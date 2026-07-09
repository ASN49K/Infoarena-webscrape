#include <iostream>
#include <fstream>
    using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,m,i,j,y[1025],x[1025],a[1025][1025],nr,z,v[1025];
int main()
{
    fin >> n>>m;
    for (i=1;i<=n;i++)
        fin>>x[i];
    for (i=1;i<=m;i++)
        fin>>y[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    i=n;
    j=m;
    nr=0;
    while(i>0&&j>0)
    {
        if (x[i]==y[j])
        {
            i-=1;
            j-=1;
            nr++;
            v[++z]=x[i+1];
        }
        else
            if(a[i][j]==a[i-1][j])
            {
                i-=1;
            }
            else
            {
                j-=1;
            }
    }
    fout <<nr<<'\n';
    for(i=z;i>=1;i--)
        fout<<v[i]<<" ";
    return 0;
}
