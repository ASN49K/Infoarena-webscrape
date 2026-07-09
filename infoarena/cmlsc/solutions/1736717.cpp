#include<cstdio>
#define NMax 1025
using namespace std;

short n, m, x[NMax], y[NMax], lcs[NMax][NMax], d[NMax];

int main()
{
    int i, j, k;
    FILE *fin, *fout;
    fin = fopen("cmlsc.in","r");
    fout = fopen("cmlsc.out","w");
    fscanf(fin,"%hd%hd",&n,&m);
    for(i=1; i<=n; i++)
        fscanf(fin,"%hd",&x[i]);
    for(i=1; i<=m; i++)
        fscanf(fin,"%hd",&y[i]);
    fclose(fin);

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(x[i] == y[j])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else if(lcs[i-1][j] > lcs[i][j-1])
                lcs[i][j] = lcs[i-1][j];
            else
                lcs[i][j] = lcs[i][j-1];

    for(k=0, i=n, j=m; lcs[i][j]; )
        if(x[i] == y[j])
        {
            d[k++] = x[i];
            i--;
            j--;
        }
        else if(lcs[i][j] == lcs[i-1][j])
            i--;
        else
            j--;

    fprintf(fout,"%hd\n",lcs[n][m]);
    for(i=k-1; i>=0; i--)
        fprintf(fout,"%hd ",d[i]);
    fprintf(fout,"\n");
    fclose(fout);
    return 0;
}
