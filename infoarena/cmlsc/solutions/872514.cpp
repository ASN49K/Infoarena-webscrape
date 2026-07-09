#include<iostream>
#include<fstream>
using namespace std;
int n,m,i,j,a[1026],b[1026],d[1026][1026],x[1026],k;
char e[1026][1026];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
                e[i][j]='/';
            }
            else
            {
                d[i][j]=d[i-1][j];
                e[i][j]='|';
                if (d[i][j-1]>d[i][j])
                {
                    d[i][j]=d[i][j-1];
                    e[i][j]='-';
                }
            }
    fout<<d[n][m]<<endl;
    i=n;j=m;k=0;
    while(i>0 && j>0)
    {
        if (e[i][j]=='/')
        {
            k++;
            x[k]=a[i];
            i--;j--;
        }
        else
        {
            if (e[i][j]=='-')
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    for (i=k;i>=1;i--) fout<<x[i]<<" ";
    return 0;
}
