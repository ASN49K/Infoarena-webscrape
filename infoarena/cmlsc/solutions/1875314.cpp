#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>

FILE *fin = fopen("cmlsc.in", "r");
FILE *fout = fopen("cmlsc.out", "w");

#define BUF 1 << 17
int pos = BUF;
char buf[BUF];

inline char next()  {
    if(pos == BUF)
        fread(buf, 1, BUF, fin), pos = 0;
    return buf[pos++];
}

inline int read()  {
    int x = 0;
    char ch = next();
    while(!isdigit(ch))
        ch = next();
    while(isdigit(ch))
        x = x * 10 + ch - '0', ch = next();
    return x;
}

#define MAX 1025

int v1[MAX], v2[MAX], dp[MAX][MAX];
int sol[MAX];

int main(void)  {
    int M = read(), N = read(), ind = 0, i, j;
    for(i = 1;i <= M;i++)
        v1[i] = read();
    for(i = 1;i <= N;i++)
        v2[i] = read();
    for(i = 1;i <= M;i++)
        for(int j = 1;j <= N;j++)  {
            if(v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    for(i = M, j = N;i > 0, j > 0;)  {
        if(v1[i] == v2[j])
            sol[ind++] = v1[i], i--, j--;
        else  {
            if(dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    fprintf(fout, "%d\n", ind);
    for(i = ind - 1;i >= 0;i--)
        fprintf(fout, "%d ", sol[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}
