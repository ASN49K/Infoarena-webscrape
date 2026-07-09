#include <bits/stdc++.h>

using namespace std;
int n,m,a[1025],b[1025],sol[1025][1025],v[1025],q;

void Citire()
{
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    fin.close();
}

void Solutie()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) sol[i][j]=1+sol[i-1][j-1];
            else sol[i][j]=max(sol[i][j-1],sol[i-1][j]);
        }
    }
    q=sol[n][m];
    i=n;j=m;
    while(q>0)
    {
        if(a[i]==b[j])
        {
            v[q--]=i;
            i--;j--;
        }
        else
        {
            if(sol[i-1][j]>sol[i][j-1])
                i--;
            else j--;
        }
    }
}

void Afisare()
{
    ofstream fout("cmlsc.out");
    fout<<sol[n][m];
    fout<<"\n";
    for(int i=1;i<=sol[n][m];i++)
        fout<<a[v[i]]<<" ";
    fout.close();
}

int main()
{
    Citire();
    Solutie();
    Afisare();
    return 0;
}
