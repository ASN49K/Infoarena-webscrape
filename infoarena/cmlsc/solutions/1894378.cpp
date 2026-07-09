#include <bits/stdc++.h>
#define Nmax 1050

using namespace std;

FILE *fin = fopen("cmlsc.in", "r");
FILE *fout = fopen("cmlsc.out", "w");

int N, M, A[Nmax], B[Nmax], dp[Nmax][Nmax];
stack <int> st;

inline void Read()
{
    int i;
    fscanf(fin, "%d %d", &N, &M);
    for(i = 1; i <= N; i++)
        fscanf(fin, "%d", &A[i]);
    for(i = 1; i <= M; i++)
        fscanf(fin, "%d", &B[i]);
    fclose(fin);
}

inline void Solve()
{
    int i, j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            if(A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    i = N;
    j = M;
    while(dp[i][j])
        if(A[i] == B[j])
        {
            st.push(A[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    fprintf(fout, "%d\n", dp[N][M]);
    while(!st.empty())
    {
        fprintf(fout, "%d ", st.top());
        st.pop();
    }
    fclose(fout);
}

int main()
{
    Read();
    Solve();
    return 0;
}
