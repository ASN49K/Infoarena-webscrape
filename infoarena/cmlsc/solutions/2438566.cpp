#include<cstdio>
#define MAX_N 1024
using namespace std;

int a[MAX_N+1], b[MAX_N+1], dp[MAX_N+1][MAX_N+1], n, m;
int sol[MAX_N], k;

int maxim(int x, int y) {
    if(x >= y)
        return x;
    return y;
}

void readArray() {
    int i;
    FILE* fin = fopen("cmlsc.in","r");
    fscanf(fin,"%d%d",&n,&m);
    for(i = 1; i <= n; i++)
        fscanf(fin,"%d",&a[i]);
    for(i = 1; i <= m; i++)
        fscanf(fin,"%d",&b[i]);
    fclose(fin);
}

void CMLSC() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = maxim(dp[i-1][j],dp[i][j-1]);
}

void printSol() {
    int i, j;
    FILE* fout = fopen("cmlsc.out","w");
    fprintf(fout,"%d\n",dp[n][m]);
    k = 0;
    i = n, j = m;
    while(dp[i][j]) {
        if(a[i] == b[j]) {
            sol[k++] = a[i];
            i--;
            j--;
        } else if(dp[i][j] == dp[i][j-1])
            j--;
        else i--;
    }
    for(i = k - 1; i >= 0; i--)
        fprintf(fout,"%d ",sol[i]);
    fprintf(fout,"\n");
    fclose(fout);
}

int main() {
    readArray();
    CMLSC();
    printSol();
    return 0;
}
