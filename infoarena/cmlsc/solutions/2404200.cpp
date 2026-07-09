#include <fstream>
#include <algorithm>
#include <stack>

#define NMAX 1050

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,j,x;
int v[NMAX],w[NMAX],a[NMAX][NMAX];

stack < int > s;

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
    }
    for(i=1;i<=m;i++)
    {
        f>>w[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==w[j])
                a[i][j]=a[i-1][j-1]+1;
            else
            {
                x=max(a[i-1][j-1],a[i-1][j]);
                x=max(x,a[i][j-1]);
                a[i][j]=x;
            }
        }
    }
    g<<a[n][m]<<"\n";
    i=n;j=m;
    while(i>0&&j>0)
    {
        if(v[i]==w[j])
        {
            s.push(v[i]);
            i--;j--;
        }
        else
        {
            if(a[i-1][j-1]>a[i-1][j])
            {
                if(a[i-1][j-1]>a[i][j-1])
                {
                    i--;j--;
                }
                else
                {
                    j--;
                }
            } else
            {
                if(a[i-1][j]>a[i][j-1])
                    i--;
                else
                    j--;
            }
        }
    }
    while(!s.empty())
    {
        g<<s.top()<<" ";
        s.pop();
    }
}
