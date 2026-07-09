#include<stdio.h>

FILE *f=fopen("subcom.in","r"),*g=fopen("subcom.out","w");
int x[100],y[100],c[101][101],n,m,a[101];

int main()
{
int i,j,nn=0;
fscanf(f,"%d",&n);
fscanf(f,"%d",&m);
c[0][0]=0;
for(i=1;i<=n;fscanf(f,"%d",&x[i]),c[i][0]=0,i++);
for(j=1;j<=m;fscanf(f,"%d",&y[j]),c[0][j]=0,j++);
for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
                {
                if(x[i]==y[j])
                        c[i][j]=c[i-1][j-1]+1;
                        else
                        {
                        if(c[i-1][j]>c[i][j-1])
                                c[i][j]=c[i-1][j];
                                else
                                c[i][j]=c[i][j-1];
                        }
                }
i=n;j=m;
while(i>=1||j>=1)
        {
        if(x[i]==y[j])
                {
                nn++;
                a[nn]=x[i];
                i--;
                j--;
                }
                else
                {
                if(c[i-1][j]<c[i][j-1])
                        j--;
                        else
                        i--;
                }
        }
for(i=nn;i>=1;i--)
        fprintf(g,"%d ",a[i]);
fclose(f);
fclose(g);
return 0;
}
