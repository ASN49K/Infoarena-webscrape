#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1030;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int A[NMAX],B[NMAX],M[NMAX][NMAX],sol[NMAX];
int main()
{
    int n,m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> A[i];
    for(int i = 1; i <= m; i++)
        fin >> B[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i] == B[j])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j] = max(M[i-1][j],M[i][j - 1]);
        }
    }
    int nmx = M[n][m];
    int  i = n,j = m;
    while(nmx != 0){
        while(M[i][j] == M[i-1][j])
            i--;
        while(M[i][j - 1] == M[i][j])
            j--;
        sol[nmx] = A[i];
        nmx --; j --; i --;

    }
    fout << M[n][m] << "\n";
    for(int i = 1; i <= M[n][m]; i++)
        fout << sol[i] <<" ";
    return 0;
}
