#include <stdio.h>
#define max(a,b) a > b ? a : b
#define MAX 100000
unsigned int v[MAX], dp[MAX], cmsc[MAX + 1];

int main()
{
    int n, i, j, max_pos, cmsc_pos, last_pos;
    FILE * fin, *fout;
    fin = fopen("scmax.in", "r");
    fout = fopen("scmax.out", "w");

    fscanf(fin, "%u", &n);
    for (i = 0;i < n;i++) {
        fscanf(fin, "%u", &v[i]);
    }
    dp[0] = 1;
    for (i = 1;i < n;i++) {
        dp[i] = 1;
        for (j = 0;j < i;j++) 
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    max_pos = 0;
    for (i = 0;i < n;i++) {
        max_pos = dp[max_pos] < dp[i] ? i : max_pos;
    }

    cmsc_pos = dp[max_pos];
    cmsc[cmsc_pos] = v[max_pos];
    last_pos = max_pos;
    cmsc_pos--;
    for (i = max_pos - 1; cmsc_pos >= 0 && i >= 0 ;i--) {
        if (v[last_pos] > v[i] && (dp[last_pos] == dp[i] + 1)) {
            cmsc[cmsc_pos] = v[i];
            cmsc_pos--;
            last_pos = i;
        }
    }

    fprintf(fout, "%d\n", dp[max_pos]);
    for (i = 1;i <= (int)dp[max_pos];i++) {
        fprintf(fout, "%d ", cmsc[i]);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
