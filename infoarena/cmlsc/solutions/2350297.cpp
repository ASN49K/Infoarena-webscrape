#include <bits/stdc++.h>
#define nmax 1026
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M,A[nmax],B[nmax],bst;
int D[nmax][nmax],sir[nmax];

void citire(){
    fin>>M>>N;
    for(int i=1;i<=M;i++)
        fin>>A[i];
    for(int i=1;i<=N;i++)
        fin>>B[i];
}

void rezolvare(){
    citire();
    int i,j;
     FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (int i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    fout<<bst<<"\n";
    for(i=bst;i>=1;i--)
        fout<<sir[i]<<" ";
}

int main()
{
    rezolvare();
    return 0;
}
