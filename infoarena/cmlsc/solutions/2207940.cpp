#include<cstdio>
#define MAX_N 1024
using namespace std;

short a[MAX_N], b[MAX_N], c[MAX_N], dp[MAX_N+1][MAX_N+1], n, m, k;

inline int maxim(int x, int y) {
    if(x >= y) return x;
    return y;
}

int main() {
    int i, j;
    FILE* fin, *fout;
    fin = fopen("cmlsc.in","r");
    fout = fopen("cmlsc.out","w");
    fscanf(fin,"%hd%hd",&n,&m);
    for(i = 0; i < n; i++)
        fscanf(fin,"%hd",&a[i]);
    for(i = 0; i < m; i++)
        fscanf(fin,"%hd",&b[i]);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = maxim(dp[i-1][j],dp[i][j-1]);

    fprintf(fout,"%hd\n",dp[n][m]);
    i = n;
    j = m;
    while(dp[i][j]) {
        if(a[i-1] == b[j-1]) {
            c[k++] = a[i-1];
            i--;
            j--;
        } else if(dp[i][j] == dp[i-1][j])
            i--;
        else j--;
    }
    for(i = k - 1; i >= 0; i--)
        fprintf(fout,"%hd ",c[i]);
    fprintf(fout,"\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
