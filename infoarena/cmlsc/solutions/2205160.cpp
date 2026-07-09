#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NM=2000;
int a[NM][NM],x[NM],y[NM],n,m;

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int i=1;i<=m;i++)
        fin>>y[i];
}

void dinamica()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else if(a[i-1][j]>a[i][j-1])
                a[i][j]=a[i-1][j];
            else a[i][j]=a[i][j-1];
}

void drum(int i,int j)
{
    if(i!=0&&j!=0)
    {
        if(x[i]==y[j])
        {
            drum(i-1,j-1);
            fout<<x[i]<<" ";
        }
        else if(a[i][j]==a[i][j-1])
            drum(i,j-1);
        else if(a[i][j]==a[i-1][j])
            drum(i-1,j);
    }
}

int main()
{
    citire();
    dinamica();
    fout<<a[n][m]<<endl;
    drum(n,m);
    fout.close();
    fin.close();
}
