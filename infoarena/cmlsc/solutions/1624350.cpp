#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],d[1025],c[1025][1025];
int main()
{
    int n,m,i,j,k;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]){c[i][j]=1+c[i-1][j-1];}
            else
            {
                    if(c[i][j-1]>c[i-1][j])c[i][j]=c[i][j-1];
                    else c[i][j]=c[i-1][j];
            }
        }
    i=n;j=m;k=0;
    do{
        if(a[i]==b[j]) d[++k]=a[i];
        if(c[i-1][j]>c[i][j-1]){i--;}
        else j--;
    }while(i>=1 && j>=1);

    fout<<c[n][m]<<'\n';
    for(i=k;i>=1;i--)
        fout<<d[i]<<' ';
    return 0;
}
