#include <iostream>
#include <fstream>
#

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1026][1026];
int x[1025],y[1025],z[1024];

int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>x[i];
    for(i=1;i<=m;i++)
        fin>>y[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    fout<<a[n][m]<<endl;
    int h=0;
    i--;j--;
    while(a[i][j]!=0)
    {
        while(a[i][j]==a[i-1][j])
            i--;
        while(a[i][j]==a[i][j-1])
            j--;
        z[++h]=x[i];
        i--;j--;
    }
    for(i=h;i>0;i--)
        fout<<z[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
