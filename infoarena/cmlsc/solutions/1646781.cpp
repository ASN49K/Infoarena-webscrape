#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <stack>
using namespace std;

int n,m;
short v1[1026],v2[1026];
short sol[1026][1026];
stack<int> s;

int main()
{
    int i,j,nr;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&v1[i]);
    for(i=1;i<=m;i++) scanf("%d",&v2[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
            if(v1[i]==v2[j]) sol[i][j]++;
        }
    printf("%d\n",sol[n][m]);
    i=n;j=m;
    while(sol[i][j])
    {
        nr=sol[i][j];
        while(sol[i-1][j]==nr) i--;
        while(sol[i][j-1]==nr) j--;
        s.push(v1[i]);
        i--;
    }
    while(!s.empty())
    {
        printf("%d ",s.top()); s.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
