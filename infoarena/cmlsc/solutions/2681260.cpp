#include<bits/stdc++.h>
using namespace std;
vector<int> afis;
int l[1030][1030],v1[1030],v2[1030];
int cmlsc(int n,int m)
{
    int max1=0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(v1[i]==v2[j])
                {
                    l[i][j]=1+l[i-1][j-1];
                    if(max1<l[i][j])
                    {
                        max1=l[i][j];
                        afis.push_back(v1[i]);
                    }
                }
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    return l[n][m];
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&v1[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d",&v2[i]);
        printf("%d\n",cmlsc(n,m));
    for(int i = 0; i< afis.size(); i++)
        printf("%d ",afis[i]);
    printf("\n");
    return 0;
}
