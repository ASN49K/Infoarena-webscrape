#include<stdio.h>
int v[1030],k[1030],mat[1030][1030];
void refac(int i,int j, FILE * fout);
int main(void)
{
    FILE * fin = fopen("cmlsc.in","rt");
    FILE * fout = fopen("cmlsc.out","wt");
    int i,j,l,r,s,m,n,p;
    fscanf(fin,"%d%d",&n,&m);
    for(i = 1; i <= n;i++)
        fscanf(fin,"%d",v + i);
    for(j = 1; j <= m; j++)
        fscanf(fin,"%d",k+j);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            if(v[i]==k[j])
                mat[i][j]=1 + mat[i - 1][j - 1];
            else
                mat[i][j]=(mat[i - 1][j] > mat[i][j - 1]) ? mat[i-1][j] : mat[i][j-1];
        }
    fprintf(fout,"%d\n",mat[n][m]);
    refac(n,m, fout); 
    fclose(fin);
    fclose(fout);
}
 
void refac(int i,int j, FILE * fout)
{
    if(i == 0|| j == 0)return;
    if(v[i] == k[j])
    {
        refac(i - 1, j - 1, fout);
        fprintf(fout,"%d ",v[i]);
        return;
    }
    if(mat[i-1][j] > mat[i][j-1])
        refac(i - 1, j, fout);
    else
        refac(i, j - 1, fout);
}
