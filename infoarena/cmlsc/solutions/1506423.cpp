#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int m, n;
    f>>n>>m;
    //vector<int> a(m);
    //vector<int> b(n);
    int a[n+1], b[m+1];
    vector<int> s;
    for(int i=1; i<=n; i++)
    {
        f>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        f>>b[i];
    }
    int d[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        d[i][0]=0;
    }
    for(int i=1; i<=m; i++)
    {
        d[0][i]=0;
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
                d[i][j]=max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    for(int i=n, j=m; i>0;)
    {
        if(a[i]==b[j])
        {
            s.push_back(a[i]);
            i--; j--;
        }
        else
        {
            if(d[i-1][j]>=d[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    g<<d[n][m]<<"\n";
    for(vector<int>::reverse_iterator it=s.rbegin(); it!=s.rend(); it++)
    {
        g<<*it<<" ";
    }
    return 0;
}
