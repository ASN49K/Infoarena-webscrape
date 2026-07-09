#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025],b[1025],c[1025][1025],s[1025];
int main()
{
    int n,m,k=0;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])   
                c[i][j]=c[i-1][j-1]+1;
            else
            {
                if(c[i-1][j]>c[i][j-1])
                    c[i][j]=c[i-1][j];
                else
                    c[i][j]=c[i][j-1];
            }
    fout<<c[n][m]<<'\n';
    while(c[n][m])
    {
        if(a[n]==b[m])
        {
            k++;
            s[k]=a[n];
            n--;
            m--;
        }
        else
        {
            if(c[n-1][m]>c[n][m-1])
                n--;
            else
                m--;
        }
    }
    while(k)
    {
        fout<<s[k]<<" ";
        k--;
    }
    return 0;
}
