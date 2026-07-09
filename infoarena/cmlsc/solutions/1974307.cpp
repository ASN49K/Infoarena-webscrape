#include <bits/stdc++.h>

using namespace std;
int DP[2005][2005];
int A[2005],B[2005], N, M;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d",&N, &M);
    for(int i = 1; i <= N; ++i)
        scanf("%d",A + i);
    for(int i = 1; i <= M; ++i)
        scanf("%d",B + i);

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], max(DP[i][j-1], DP[i-1][j-1]));

    printf("%d\n",DP[N][M]);
    int ic = N, jc = M, sz = DP[N][M];
    vector<int> sol;
    while(ic && jc) {
        if(A[ic] == B[jc]) {
            sol.push_back(A[ic]);
            ic = ic - 1;
            jc = jc - 1;
            continue;
        }
        if(DP[ic-1][jc] > DP[ic][jc-1]) {
            ic -= 1;
        }
        else
            jc -= 1;
    }
    reverse(sol.begin(), sol.end());
    for(auto it : sol)
        printf("%d ", it);
    printf("\n");

    return 0;
}
