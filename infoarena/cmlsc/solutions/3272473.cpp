#include <bits/stdc++.h>

using namespace std;
const int MAXN=1024;

int dp[MAXN+1][MAXN+1];
int drum[MAXN+1], sir[MAXN+1], sir2[MAXN+1];

static inline int max(int a, int b){
    return a > b ? a : b;
}

signed main()
{
    FILE *fin, *fout;
    int n, m, i, j, k;
    fin=fopen("cmlsc.in", "r");
    fscanf(fin, "%d%d", &n, &m);
    for(i=1; i<=n; i++)
        fscanf(fin, "%d", &sir[i]);
    for(i=1; i<=m; i++)
        fscanf(fin, "%d", &sir2[i]);
    fclose(fin);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(sir[i]==sir2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);

    k=0;
    while(n>0 && m>0){
        if(sir[n]==sir2[m]){
            drum[k++]=sir[n];
            n--;
            m--;
        }else if(dp[n-1][m]>dp[n][m-1])
            n--;
        else
            m--;
    }
    fout=fopen("cmlsc.out", "w");
    fprintf(fout, "%d\n", k);
    for(k--; k>=0; k--)
        fprintf(fout, "%d ", drum[k]);
    fclose(fout);
    return 0;

}
