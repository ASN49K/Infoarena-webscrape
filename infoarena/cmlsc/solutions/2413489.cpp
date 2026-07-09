#include <bits/stdc++.h>
#define Dim 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,A[Dim],B[Dim],dp[Dim],T[Dim];
int ans,id,poz;

vector <int> V[260];
deque <int> qu;

int main()
{
    f>>N>>M;
    for(int i=1;i<=N;i++) f>>A[i];
    for(int j=1;j<=M;j++)
    {
        f>>B[j];
        V[B[j]].insert(V[B[j]].begin(),j);
    }
    for(int i=1;i<=N;i++)
    {
        for(unsigned k=0;k<V[A[i]].size();k++)
        {
            int pozB=V[A[i]][k];
            dp[pozB]=1;
            T[pozB]=pozB;
            for(int j=1;j<pozB;j++)
            if(dp[pozB]<dp[j]+1)
            {
                dp[pozB]=dp[j]+1;
                T[pozB]=j;
            }
        }
    }
    for(int i=1;i<=M;i++)
    if(ans<dp[i])
    {
        ans=dp[i];
        id=i;
    }
    g<<ans<<'\n';
    for(int i=ans;i>=1;i--)
    {
        qu.push_front(B[id]);
        id=T[id];
    }
    while(!qu.empty())
    {
        g<<qu.front()<<" ";
        qu.pop_front();
    }
    return 0;
}
