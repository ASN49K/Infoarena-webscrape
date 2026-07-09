#include <bits/stdc++.h>
using namespace std;
int v1[100005],v2[100005],str[1035][1035];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&v2[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(v1[i]==v2[j])str[i][j]=str[i-1][j-1]+1;
        else
            str[i][j]=max(str[i-1][j],str[i][j-1]);
    }
    cout<<str[n][m];
    stack<int>st;
    while(n>0&&m>0)
    {
        if(v1[n]==v2[m])
        {
            st.push(v1[n]);
            --n;
            --m;
            continue;
        }
        if(str[n-1][m]==str[n][m])
        {
            --n;
        }
        else
            --m;
    }
    cout<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
