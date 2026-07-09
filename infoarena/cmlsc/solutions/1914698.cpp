#include <bits/stdc++.h>

using namespace std;

int Na,Nb,indt;
bitset<260>viza,vizb;
int a[1030],b[1030],dp[1030][1030],t[1030];

void Citire()
{
    int i,x;
    ifstream fin("cmlsc.in");
    fin>>Na>>Nb;
    for(i=1;i<=Na;++i)
    {
        fin>>x;
        viza[x]=1;
        a[i]=x;
    }
    for(i=1;i<=Nb;++i)
    {
        fin>>x;
        vizb[x]=1;
        b[i]=x;
    }
    fin.close();
}

void Dinamica()
{
    int i,j;
    for(i=1;i<=Na;++i)
        for(j=1;j<=Nb;++j)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1] + 1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
}

void Afisare()
{
    int i,j;
    i=Na;
    j=Nb;
    while(!(i==0 || j==0))
    {
        if(a[i]==b[j])
        {
            t[++indt]=a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    ofstream fout("cmlsc.out");
    fout<<dp[Na][Nb]<<"\n";
    for(i=indt;i>=1;--i)
        fout<<t[i]<<" ";
    fout<<"\n";
    fout.close();
}

int main()
{
    Citire();
    Dinamica();
    Afisare();
    return 0;
}
