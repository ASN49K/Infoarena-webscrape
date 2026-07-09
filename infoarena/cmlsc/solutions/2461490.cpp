#include <iostream>
#include <fstream>
#include <stack>

#define MAX(x,y) x>y?x:y

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dp[1025][1025], a[1025], b[1025];
stack <int> s;

void citire (int &n, int &m)
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)
        fin>>a[i];
    for (int i=1; i<=m; i++)
        fin>>b[i];
}

void din_prog (int n, int m)
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (a[i]==b[j])
                    dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=MAX(dp[i-1][j],dp[i][j-1]);
        }
}

void form_sir (int n, int m)
{
    int i=n, j=m;

    while (i>0&&j>0)
    {
        if (a[i]==b[j])
        {
            s.push(a[i]);
            i--;
            j--;
        }
        else
        {
            if (a[i-1]>b[j-1])
                i--;
            else
                j--;
        }
    }
}

int main()
{
    int n,m;

    citire (n, m);
    din_prog(n, m);
    fout<<dp[n][m]<<"\n";

    form_sir(n, m);
    while (!s.empty())
    {
        fout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
