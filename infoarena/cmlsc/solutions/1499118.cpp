#include <iostream>
#include <fstream>
#include <stack>

#define nmax 1025

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int n, m, i, j;
int A[nmax], B[nmax];
int DP[nmax][nmax];
stack <int> s;

void read()
{
    fi >> n >> m;
    for (i = 1; i <= n; i++)
        fi >> A[i];
    for (i = 1; i <= m; i++)
        fi >> B[i];
}

void buildDP()
{
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
}

void backtrack()
{
    i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (DP[i][j-1] == DP[i][j]) j--;
        else if (DP[i-1][j] == DP[i][j]) i--;
        else {
            s.push(A[i]);
            i--, j--;
        }
    }
}

void write()
{
    fo << DP[n][m] << "\n";
    while (!s.empty())
    {
        fo << s.top() << " ";
        s.pop();
    }
}

int main()
{
    
    read();
    
    buildDP();
    
    backtrack();
    
    write();

    return 0;
}