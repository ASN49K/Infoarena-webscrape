#include <iostream>
#include <fstream>
#include <stack>

#define nmax 1025

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int n, m;
int A[nmax], B[nmax], dp[nmax][nmax];
stack <int> s;

void read();
void solve();
void write();

int main()
{
    
    read();
    solve();
    write();
    
    fi.close();
    fo.close();
    
    return 0;
}

void read()
{
    
    int i;
    
    fi >> n >> m;
    
    for (i = 1; i <= n; i++)
        fi >> A[i];
    
    for (i = 1; i <= m; i++)
        fi >> B[i];
    
}

void solve()
{
    
    int i, j;
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    
    i = n, j = m;
    
    while (i > 0 && j > 0)
    {
        
        if (dp[i][j-1] == dp[i][j])
            j--;
        else if (dp[i-1][j] == dp[i][j])
            i--;
        else {
            s.push(A[i]);
            i--, j--;
        }
        
    }
    
}

void write()
{
    fo << dp[n][m] << "\n";
    while (!s.empty())
    {
        fo << s.top() << " ";
        s.pop();
    }
}