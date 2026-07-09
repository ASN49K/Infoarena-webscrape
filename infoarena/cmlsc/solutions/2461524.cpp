#include <iostream>
#include <fstream>

using namespace std;

int a[1028],b[1028],sol[1028][1028],n,m,c[1028];

ifstream fin("subsir.in");
ofstream fout("subsir.out");

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
        if(a[i]==b[j])
            sol[i][j]=sol[i-1][j-1]+1;
        else
            sol[i][j] = max(sol[i-1][j],sol[i][j-1]);
        }
        fout<<sol[n][m]<<endl;
    int i=n,j=m,k=0;
    while(sol[i][j]!=0)
    {
        if(sol[i][j]==sol[i-1][j])
            i--;
        else
            if(sol[i][j]==sol[i][j-1])
            j--;
        else
        {
        c[k++]=a[i];
        i--;
        j--;
        }

    }
    cout<<k;
    for(int i=k-1;i>=0;i--)
        fout<<c[i]<<" ";
    return 0;
}
