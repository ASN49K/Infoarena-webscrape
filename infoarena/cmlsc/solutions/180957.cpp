#include<stdio.h>

FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int x[1024],y[1024],c[1024][1024],n,m,a[1024];

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
fprintf(g,"%d\n",nn);
for(i=nn;i>=1;i--)
        fprintf(g,"%d ",a[i]);
fclose(f);
fclose(g);
return 0;
}
