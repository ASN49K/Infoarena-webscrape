#include <bits/stdc++.h>
using namespace std;
const int NMAX=1030;
int d1[NMAX],d2[NMAX];
int v[NMAX][NMAX];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int m , n , i , j;
    scanf("%d%d",&m,&n);
    for(i = 1 ; i <= m ; i++)scanf("%d",&d1[i]);
    for(i = 1; i <= n ; i++)scanf("%d",&d2[i]);
    for(i = 1; i <= m ; i++)
        for(j = 1 ; j <= n;  j++)
        if(d1[i]!=d2[j])
           v[i][j]=max(v[i-1][j],v[i][j-1]);
               else
          v[i][j] = v[i-1][j-1]+1;
    cout<<v[m][n]<<endl;
    stack<int>st;
    while(m && n)
    {
        if(d1[m] == d2[n])
        {
          st.push(d1[m]);
          --m;
          --n;
        }
        else
        {if(v[m][n-1] == v[m][n])--n;
        else
            --m;}
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
