#include <iostream>
#include <fstream>

using namespace std;

int a[1025][1025],v1[1025],v2[1025],m,n,s[1025];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void read()
{
    fin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
}

int main()
{
    int i,j;
    read();
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i-1][j]>a[i][j-1])
                a[i][j]=a[i-1][j];
            else a[i][j]=a[i][j-1];
            if(v1[i]==v2[j]) a[i][j]++;
        }
    int k,z=0;
    i=n;
    j=m;
    while(a[i][j])
    {
        k=a[i][j];
        while(j>0 && a[i][j-1]==k)
            j--;
        while(i>0 && a[i-1][j]==k)
            i--;
        s[++z]=v1[i];
        i--;
        j--;
    }
    fout<<z<<"\n";
    for(i=z;i>=1;i--)
        fout<<s[i]<<" ";
    return 0;
}
