#include <stdio.h>

#define MAX_LIN_COL 1024

short dp[MAX_LIN_COL+1][MAX_LIN_COL+1];
short v1[MAX_LIN_COL+1], v2[MAX_LIN_COL+1], sol[MAX_LIN_COL+1];

short max(short a, short b){
    return a>b?a:b;
}

int main()
{
    FILE *fin, *fout;
    int n, m, index, index2;
    fin=fopen("cmlsc.in", "r");
    fscanf(fin, "%d%d", &n, &m);
    for(index=1;index<=n;index++){
        fscanf(fin, "%hd", &v1[index]);
    }
    for(index=1;index<=m;index++){
        fscanf(fin, "%hd", &v2[index]);
    }
    fclose(fin);
    for(index=1;index<=n;index++){
        for(index2=1;index2<=m;index2++){
            if(v1[index]==v2[index2]){
                dp[index][index2]=dp[index-1][index2-1]+1;
            }
            else{
                dp[index][index2]=max(dp[index-1][index2], dp[index][index2-1]);
            }
        }
    }
    fout=fopen("cmlsc.out", "w");
    fprintf(fout, "%hd\n", dp[n][m]);
    index2=0;
    while(n>0&&m>0){
        if(v1[n]==v2[m]){
            sol[index2]=v1[n];
            index2++;
            n--;
            m--;
        }
        else{
            if(dp[n-1][m]>dp[n][m-1]){
                n--;
            }
            else{
                m--;
            }
        }
    }
    do{
        index2--;
        fprintf(fout, "%hd ", sol[index2]);
    }while(index2>0);
    fclose(fout);
    return 0;
}
