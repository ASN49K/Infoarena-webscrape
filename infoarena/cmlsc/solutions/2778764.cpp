#include<iostream>
#include<fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
int main()
{
    int i,j,m,n,a[1024],b[1024],ab[1024][1024],sir[1024];
    int k=0;
    f>>m>>n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        ab[i][j]=0;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(a[i]==b[j])
        ab[i][j]=1+ab[i-1][j-1];\
        else
        ab[i][j]=max(ab[i-1][j],ab[i][j-1]);
        o<<ab[m][n]<<'\n';
        for(i=m,j=n;j>=1&&i>=1;)
            {
                if(a[i]==b[j])
                {
                    k++;
                    sir[k]=a[i];
                    i--;
                    j--;
                }
                else if(ab[i-1][j]>ab[i][j-1])
                        i--;
                        else
                        j--;
            }
            for(i=k;i>=1;i--)
                o<<sir[i]<<" ";



}
