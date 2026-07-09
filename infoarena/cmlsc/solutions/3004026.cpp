#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int din[1025][1025],hello,i,j,n,m,a[1025],b[1025];
int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for (i=1;i<=m;i++)
    {
        f>>b[i];
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            hello = din[i-1][j-1]+1;
            din[i][j] = max(din[i-1][j],din[i][j-1]);
            if (a[i]==b[j])
            {
                din[i][j]=max(din[i][j],hello);
            }
        }
    }
    vector <int> sol;
    g<<din[n][m]<<'\n';
    while (n>0 && m >0)
    {
        if (a[n]==b[m])
        {
            sol.push_back(a[n]);
            n--;
            m--;
        }
        else
        {
            if (din[n-1][m]<din[n][m-1])
            {
                m--;
            }
            else
            {
                n--;
            }
        }
    }
    for (j=(int)sol.size()-1;j>=0;j--)
    {
        g<<sol[j]<<" ";
    }
    return 0;
}
