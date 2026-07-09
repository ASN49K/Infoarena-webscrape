#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,c[1026][1026],a[1026],b[1026],s[1026],vf=0;

int main()
{
    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            c[i][j]=1+c[i-1][j-1];
        else
        c[i][j]=max(c[i-1][j],c[i][j-1]);

    }

    for(int i=n,j=m;i&&j;)
    {
        if(a[i]==b[j])
            {
                s[++vf]=a[i];
                i--;
                j--;

            }
        else
            if(c[i-1][j]>c[i][j-1])
            i--;
        else
            j--;
    }

    fout<<vf<<endl;

    for(int i=vf;i>=1;i--)
        fout<<s[i]<<" ";

    return 0;
}
