#include <iostream>
#include <fstream>

using namespace std;

int n,m,i,j,x[1025],y[1025],a[1025][1025],sir[1025],k;
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>x[i];
    for(i=1;i<=m;i++)
    fin>>y[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(x[i]==y[j])
        a[i][j]=a[i-1][j-1]+1;
    else a[i][j]=max(a[i][j-1],a[i-1][j]);
    fout<<a[n][m]<<endl;
    i=n;j=m;
    while(i && j)
    {
        if(x[i]==y[j])sir[++k]=x[i],i--,j--;
        else
        {
            if(a[i][j-1]>a[i-1][j])j--;
            else i--;
        }
    }
    for(i=k;i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
