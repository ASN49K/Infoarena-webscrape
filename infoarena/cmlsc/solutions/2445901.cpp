#include<cstdio>
#define MAX_N 1024

short a[MAX_N+1], b[MAX_N+1], dp[MAX_N+1][MAX_N+1], sol[MAX_N+1];
int n, m, len;

inline int maxim(int x, int y) {
    if(x >= y)
        return x;
    return y;
}

void read() {
    int i;
    FILE* fin = fopen("cmlsc.in","r");
    fscanf(fin,"%d%d",&n,&m);
    for(i = 1; i <= n; i++)
        fscanf(fin,"%hd",&a[i]);
    for(i = 1; i <= m; i++)
        fscanf(fin,"%hd",&b[i]);
    fclose(fin);
}

void CMLSC() {
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = maxim(dp[i-1][j],dp[i][j-1]);
}

void printSol() {
    int i, j;
    FILE* fout = fopen("cmlsc.out","w");
    fprintf(fout,"%hd\n",dp[n][m]);
    i = n, j = m;
    len = 0;
    while(dp[i][j]) {
        if(a[i] == b[j]) {
            sol[len++] = a[i];
            i--;
            j--;
        }else if(dp[i-1][j] == dp[i][j])
            i--;
        else j--;
    }
    for(i = len - 1; i >= 0; i--)
        fprintf(fout,"%hd ",sol[i]);
    fprintf(fout,"\n");
    fclose(fout);
}

int main() {
    read();
    CMLSC();
    printSol();
    return 0;
}
