#include<bits/stdc++.h>
using namespace std;
int v1[1030],v2[1030];
stack<int> afis;
int cmlsc(int n,int m)
{
    if(n==0 || m==0)
        return 0;
    if(v1[n]==v2[m])
    {
        afis.push(v1[n]);
        return 1+cmlsc(n-1,m-1);
    }
        else return max(cmlsc(n-2,m-1),cmlsc(n-1,m-2));
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&v2[i]);
    printf("%d\n",cmlsc(n,m));
    while(!afis.empty())
    {
        printf("%d ",afis.top());
        afis.pop();
    }
    return 0;
}
