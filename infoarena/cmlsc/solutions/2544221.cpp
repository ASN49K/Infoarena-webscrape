#include <bits/stdc++.h>
using namespace std;
int n1,n2;
int v1[10005],v2[10005];
int d[1025][1025];
int main()
{
    freopen("cmslc.in","r",stdin);
    freopen("cmslc.out","w",stdout);
    scanf("%d%d",&n1,&n2);
    for(int i=1;i<=n1;i++)scanf("%d",&v1[i]);
    for(int i=1;i<=n2;i++)scanf("%d",&v2[i]);
    d[0][0]=0;
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++)
    {
        if(v1[i]==v2[j])
        {
            d[i][j]=d[i-1][j-1]+1;
        }
        else
            d[i][j]=max(d[i][j-1],d[i-1][j]);
    }
    cout <<d[n1][n2]<<"\n";
    stack<int>st;
    while(n1!=0&&n2!=0)
    {
        if(v1[n1]==v2[n2])
        {
            st.push(v1[n1]);
            --n1;
            --n2;
            continue;
        }
        if(d[n1][n2-1]>=d[n1-1][n2])
        {
            --n2;
        }
        else
            --n1;
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
