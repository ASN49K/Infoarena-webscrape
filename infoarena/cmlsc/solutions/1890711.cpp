#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, A[1030], B[1030], D[1030][1030];
stack<int> sol;

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
    for(int i=n, j=m; i;)
    {
        if(A[i] == B[j]){sol.push(i);i--; j--;}
        else if(D[i-1][j] < D[i][j-1]) j--;
        else i--;
    }
    fout<<D[n][m]<<'\n';
    while(!sol.empty())
    {
        fout<<A[sol.top()]<<' ';
        sol.pop();
    }

    return 0;
}
