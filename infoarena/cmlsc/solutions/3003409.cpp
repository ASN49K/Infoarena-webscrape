#include <bits/stdc++.h>
using namespace std;
int v[1025][1025],a[1025],b[1025];
int main()
{
    int m ,n,i,j;
    cin>>m>>n;
    for(i=1;i<=m;i++)
        cin>>a[i];
    for(j=1;j<=n;j++)
        cin>>b[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(a[i]==b[j])
        v[i][j]=v[i-1][j-1]+1;
    else
        v[i][j]=max(v[i-1][j],v[i][j-1]);
    cout<<v[m][n]<<endl;
    stack<int>st;
    while(m*n)
    {
        if(a[m] == b[n])
        {
            st.push(a[m]);
            --m;
            --n;
            continue;
        }
        if(v[m][n]==v[m-1][n])
            --m;
        else
            --n;
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
