#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,k;
int a[1030],b[1030],s[1030][1030],sol[1030];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                s[i][j]=s[i-1][j-1]+1;
            else
                s[i][j]=max(s[i-1][j],s[i][j-1]);
        }
    }

    k=0;
    i=n,j=m;
    while(i!=0)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;j--;
        }
        else
            if(s[i-1][j]>s[i][j-1])
                i--;
            else j--;

    }

    fout<<k<<"\n";
    for(i=k;i>=1;i--)
        fout<<sol[i]<<" ";

    fout.close();
    fout.close();
    return 0;
}
