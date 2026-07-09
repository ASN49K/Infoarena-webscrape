#include<stdio.h>


int i,j,k,m,n;
int   v[1025][1025],a[1025],b[1025];

FILE *g=fopen("cmlsc.out","w");

void af(int i,int j,int k){
        while((i||j)&&i&&j)
                {if(a[i]==b[j]&&v[i][j]==k)
                        {af(i-1,j-1,k-1);
                        fprintf(g,"%d ",a[i]);
                        return ;
                        }
               else
               if(v[i][j]==v[i-1][j])i--;
               else
               j--;
                }
}
int main(){

FILE *f=fopen("cmlsc.in","r");
fscanf(f,"%d %d",&n,&m);

for(i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);

for(i=1;i<=m;i++)
        fscanf(f,"%d",&b[i]);

fclose(f);

for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
        if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
       else
        if(v[i-1][j]>v[i][j-1])v[i][j]=v[i-1][j];
       else
       v[i][j]=v[i][j-1];
fprintf(g,"%d\n",int(v[n][m]));
af(n,m,v[n][m]);
fclose(g);
return 0;}
