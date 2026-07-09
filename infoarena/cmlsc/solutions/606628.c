#include <stdio.h>
#include <stdlib.h>
#define maxi(a,b) (((a)>(b))?(a):(b))
#define Max 1024


int n,m;
int c[Max+1][Max+1];
int a[Max],b[Max];


void read();
void road();
void path(int ,int , int);
void afis();
FILE *fpo;

int main()
{
    fpo = fopen("cmlsc.out","w");

    read();
    road();
    afis();

    return 0;
}

void read()
{
   FILE *fpi;
   int i;

   fpi = fopen("cmlsc.in","r");

   fscanf(fpi,"%d %d",&m,&n);

    for(i = 1; i <= m; i++)
    fscanf(fpi,"%d",&a[i]);

    for(i = 1; i <= n; i++)
    fscanf(fpi,"%d",&b[i]);

    fclose(fpi);


}

void afis()
{
  //  fprintf(fpo,"%d %d\n",m,n);

  /*  for(int i = 1; i <= m; i++)
    fprintf(fpo,"%d ",a[i]);
    fprintf(fpo,"\n");
    for(int i = 1; i <= n; i++)
    fprintf(fpo,"%d ",b[i]);

    fprintf(fpo,"\n\n");

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        fprintf(fpo,"%d ",c[i][j]);
        fprintf(fpo,"\n");
    }
*/
    fprintf(fpo,"%d\n",c[m][n]);
    path(m,n,c[m][n]);

    fclose(fpo);

}
void path(int i,int j,int k)
{
    if(k != 0)
    {
        int maxim = 0;
        maxim = maxi(c[i][j-1],c[i-1][j]);
        if(maxim == k)
        {
            if(c[i][j-1] == k)
            path(i,j-1,k);
            else if(c[i-1][j] == k)
            path(i-1,j,k);
        }
        if(maxim + 1 == k)
        {
            path(i-1,j-1,k-1);
            fprintf(fpo,"%d ",a[i]);
        }
    }

}
void road()
{
    int i,j;
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
        if(a[i] == b[j])
        c[i][j] = c[i-1][j-1] + 1;
        else if(a[i] != b[j])
            c[i][j] = maxi(c[i][j-1],c[i-1][j]);
        }
    }

}
