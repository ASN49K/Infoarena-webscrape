#include<cstdio>
#define N_MAX 1024
using namespace std;

int a[N_MAX], b[N_MAX], s[N_MAX], lcs[N_MAX+1][N_MAX+1], n, m, nr;

void Read()
{
    int i;
    FILE *fin = fopen("cmlsc.in","r");
    fscanf(fin,"%d%d",&n,&m);
    for(i=0; i<n; i++)
        fscanf(fin,"%d",&a[i]);
    for(i=0; i<m; i++)
        fscanf(fin,"%d",&b[i]);
    fclose(fin);
}

int maxim(int x, int y)
{
    if(x > y) return x;
    return y;
}

void CMLSC()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i-1] == b[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else lcs[i][j] = maxim(lcs[i][j-1],lcs[i-1][j]);
}

void Write()
{
    int i, j;
    FILE *fout = fopen("cmlsc.out","w");
    fprintf(fout,"%d\n",lcs[n][m]);
    i = n; j = m;
    while(lcs[i][j])
    {
        if(a[i-1] == b[j-1])
        {
            s[nr++] = a[i-1];
            i--;
            j--;
        }
        else if(lcs[i-1][j] == lcs[i][j])
            i--;
        else j--;
    }
    for(i=nr-1; i>=0; i--)
        fprintf(fout,"%d ",s[i]);
    fprintf(fout,"\n");
    fclose(fout);
}

int main()
{
    Read();
    CMLSC();
    Write();
    return 0;
}


