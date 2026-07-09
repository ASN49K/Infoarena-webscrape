#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int l[1024][1024],a[1024],b[1024],n,m,c[1024];

int main()
{
    int i,j,nr=0;
fin>>m>>n;
for(i=1;i<=m;i++)
    fin>>a[i];
for(i=1;i<=n;i++)
    fin>>b[i];
for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
        {if(i==0||j==0)
            l[i][j]=0;
        if(i!=0&&j!=0&&a[i]==b[j])
            l[i][j]=1+l[i-1][j-1];
        if(i!=0&&j!=0&&a[i]!=b[j])
            l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
i=m;
j=n;
fout<<l[i][j]<<"\n";
while(l[i][j]!=0)
{
    if(a[i]==b[j])
        {
            c[++nr]=a[i];
            i--;
            j--;
        }
    if(l[i][j-1]>l[i-1][j])
        j--;
    else
        i--;

}
for(i=nr;i>=1;i--)
    fout<<c[i]<<" ";
    return 0;
}
