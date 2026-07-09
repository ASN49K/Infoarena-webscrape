#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],d[1025][1025],n,m,str[1025],nr;
int main()
{
    in >>n>>m;
    for(int i=1; i<=n; i++)
    {
        in >> a[i];
    }
    for(int j=1; j<=m; j++)
    {
        in >> b[j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    for(int i=n,j=m; i && j;)
    {
        if(a[i]==b[j])
        {
            str[++nr]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    out << nr << '\n';
    for(int i=nr; i; i--)
    {
        out << str[i] << ' ';
    }
    return 0;
}
