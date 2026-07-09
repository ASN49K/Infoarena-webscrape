#include <bits/stdc++.h>

using namespace std;

int n,m,t[1030][1030],i,a[1030],q[1030],j;
stack <int> s;

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>n>>m;
    for (i=1; i<=n; i++)
        cin>>a[i];
    for (j=1; j<=m; j++)
        cin>>q[j];

    for (i=1; i<=m; i++)
    for (j=1; j<=n; j++)
    {
        if (q[i]==a[j]) t[i][j]=t[i-1][j-1]+1;
        else t[i][j]=max(t[i-1][j],t[i][j-1]);
    }
    i=m;
    j=n;
    while (i && j)
    {
        if (t[i][j-1]<t[i][j]) {s.push(a[j]); i--; j--;} else j--;
    }
    cout<<t[m][n]<<endl;
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
