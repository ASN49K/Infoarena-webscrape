#include <bits/stdc++.h>

using namespace std;

int N,M,indt;
bitset<260>viz;
int a[1030],b[1030],dp[1030],pred[1030],t[1030];

void Citire()
{
    int i,x;
    ifstream fin("cmlsc.in");
    fin>>N>>M;
    for(i=1;i<=N;++i)
    {
        fin>>x;
        viz[x]=1;
        a[i]=x;
    }
    for(i=1;i<=M;++i)
        fin>>b[i];
    fin.close();
}

void Dinamica()
{
    int i,j,maxim;
    for(i=1;i<=N;++i)
    {
        maxim=0;
        for(j=1;j<i;++j)
            if(dp[j]>maxim)
            {
                maxim=dp[j];
                pred[i]=j;
            }
        dp[i]=maxim;
        if(viz[b[i]]==1)
            dp[i]++;
    }
}

void Afisare()
{
    int i;
    i=M;
    while(i!=0)
    {
        t[++indt]=b[i];
        i=pred[i];
    }
    ofstream fout("cmlsc.out");
    fout<<dp[M]<<"\n";
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
