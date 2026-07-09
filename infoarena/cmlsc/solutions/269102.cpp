#include<stdio.h>


int i,j,k,m,n;
char   v[1030][1030],a[1030],b[1030];

FILE *g=fopen("cmlsc.out","w");

void af(int i,int j){
        while(i||j)
                {if(a[i]==b[j])
                        {af(i-1,j-1);
                        fprintf(g,"%d ",int(a[i]));
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
        {fscanf(f,"%d",&k);
        a[i]=k;
        }

for(i=1;i<=m;i++)
        {fscanf(f,"%d",&k);
        b[i]=k;
        
        }

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
af(n,m);
return 0;}
