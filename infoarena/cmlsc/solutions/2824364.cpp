#include <bits/stdc++.h>

using namespace std;
 
int maxim(int a, int b) 
{
    if(a>b)
        return a;
    else
        return b;
}

 
int M, N, A[1024], B[1024], D[1024][1024], sir[1024], bst;
 
int main(void)
{
    int i, j;
    
    ifstream f ("cmlsc.in");
    ofstream g("cmlsc.out");
 
    f >> M >> N;
    for (i=1; i<= M; i++)
        f>> A[i];
    for (j=1; j<= M; j++)
        f>> B[j];
 
    for (i=1; i<= M; i++)
        for (j=1; j<= M; j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
 
    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
 
    g << bst << '\n';
    for (i = bst; i; --i)
        g << sir[i] << ' ';
 
    return 0;
}