#include <bits/stdc++.h>

using namespace std;
ifstream fin("scmax.in");
ofstream fout("scmax.out");
typedef long long ll;
int dp[100001],n,v[100001],maxim,maxi[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    fout.tie(0);
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>v[i];
    dp[n]=1;
    maxi[1]=v[n];
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=1;
        int st=1;
        int dr=n;
        int pozmax=0;
        while(st<=dr)
        {
            int mij=(st+dr)/2;
            if(maxi[mij]>v[i])
            {
                if(mij>pozmax)
                    pozmax=mij;
                st=mij+1;
            }
            else
                dr=mij-1;
        }
        dp[i]=pozmax+1;
        if(maxi[dp[i]]<v[i])
            maxi[dp[i]]=v[i];
        if(maxim<dp[i])
            maxim=dp[i];
    }
    fout<<maxim<<'\n';
    int cr=0;
    int pls=maxim;
    for(int i=1;i<=n;i++)
        if(dp[i]==pls)
        {
            if(v[i]>cr)
            {
                cr=v[i];
                pls--;
                fout<<cr<<" ";
            }
        }
    return 0;
}
