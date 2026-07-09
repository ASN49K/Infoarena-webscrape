#include <bits/stdc++.h>
using namespace std;
#define NMAX 1030

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[NMAX], b[NMAX], mat[NMAX][NMAX];
stack <int> sol;

int main()
{
     fin >> n >> m;
     for(int i = 1; i <= n; i++)
        fin >> a[i];

     for(int  i = 1; i <= m ; i++)
        fin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);

    fout << mat[n][m] <<"\n";


    int i1 = n, i2 = m, k=mat[n][m];
    for(; k > 0; )
        if(a[i1] == b[i2])
        {
            sol.push(a[i1]);
            i1--, i2--; k--;
        }
        else
            if(mat[i1-1][i2]<mat[i1][i2-1])
                i2--;
            else
                if(mat[i1-1][i2] > mat[i1][i2-1])
                    i1--;
                else
                    if(i1>0) i1--;
                    else i2--;

    while(!sol.empty())
    {
        fout<<sol.top()<<" ";
        sol.pop();
    }

}

