#include <stdio.h>
#define nmax 1024
using namespace std;

int n,m,x[nmax],y[nmax],c[nmax][nmax];
FILE *fout=fopen("cmlsc.out","w");

    void read(void)
    {
        FILE *fin=fopen("cmlsc.in","r");
        int i;
        fscanf(fin,"%d%d",&n,&m);
        for(i=1;i<=n;i++) fscanf(fin,"%d",x+i);
        for(i=1;i<=m;i++) fscanf(fin,"%d",y+i);
        fclose(fin);
    }

    int lungime(void)
    {
        int i,j;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
                else if(c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
                    else c[i][j]=c[i][j-1];
        return c[n][m];
    }

    void afisare(int i,int j)
    {
        if(i==0 || j==0) return;
        if(x[i]==y[j]) afisare(i-1,j-1), fprintf(fout,"%d ",x[i]);
        else if(c[i-1][j]>c[i][j-1]) afisare(i-1,j);
            else afisare(i,j-1);
    }

int main(void)
{
    read();
    fprintf(fout,"%d\n",lungime());
    afisare(n,m);
    fclose(fout);
    return 0;
}
