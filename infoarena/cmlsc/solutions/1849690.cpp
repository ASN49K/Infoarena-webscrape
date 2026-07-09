#define MAX 1024
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int a[MAX],b[MAX],s[MAX];
int d[MAX][MAX];
int main ()
{
    fin>>n>>m;
    int ct=1;
    for (int i=1;i<=n;i++)
        fin>>a[i];
    for (int i=1;i<=m;i++)
        fin>>b[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    }
    fout<<d[n][m]<<"\n";
    int i=n;
    int j=m;
    while (i!=0 && j!=0)
    {
        if (a[i]==b[j])
        {
            s[ct]=a[i];
            ct++;
            i--;
            j--;
        }
        else if (d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    for (int q=ct-1;q>0;q--)
        fout<<s[q]<<" ";
}
