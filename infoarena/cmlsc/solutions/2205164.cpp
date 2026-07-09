#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[2005][2005],x[2005],y[2005],n,m;
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int i=1;i<=m;i++)
        fin>>y[i];
}
void dinam()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else if(a[i][j-1]>a[i-1][j])
                    a[i][j]=a[i][j-1];
                else a[i][j]=a[i-1][j];
}
void drum(int i,int j)
{
    if(i!=0&&j!=0)
        if(x[i]==y[j])
        {
            drum(i-1,j-1);
            fout<<x[i]<<" ";
        }
        else if(a[i][j]==a[i][j-1])
                drum(i,j-1);
            else drum(i-1,j);
}
int main()
{
    citire();
    dinam();
    fout<<a[n][m]<<endl;
    drum(n,m);
    fin.close();
    fout.close();
    return 0;
}
