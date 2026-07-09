#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, A[1050], B[1050], D[1050][1050];
stack<int> s;

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> A[i];
    for(int i=1; i<=m; i++)
        fin >> B[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i] == B[j]) D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = max(D[i-1][j], D[i][j-1]);
        }
    }
    for(int x=n, y=m; x;)
    {
        if(A[x] == B[y])
        {
            s.push(A[x]);
            x--;
            y--;
        }
        else if(D[x-1][y] >= D[x][y-1]) x--;
        else y--;
    }
    fout<<D[n][m]<<'\n';
    while(!s.empty())
    {
        fout<<s.top()<<' ';
        s.pop();
    }

    return 0;
}
