#include<stdio.h>
int mat[103][103],x[103],z[103],i,j,n,m,k=0,w[103];

int max (int a,int b)
{
if (a>b)return a;
return b;
}


int main (){

FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");


fscanf(f,"%d %d",&n,&m);

for (i=1;i<=n;i++) fscanf(f,"%d",&x[i]);
for (i=1;i<=m;i++) fscanf(f,"%d",&z[i]);


for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
     {
      if (x[j]==z[i]) mat[i][j]=mat[i-1][j-1]+1;
	 else mat[i][j]=max(mat[i-1][j],mat [i][j-1]);
     }

i=m;j=n;
while (i!=0&&j!=0)
{if (x[j]==z[i]) {w[++k]=z[i];i--;j--;}
    else if (mat[i-1][j]<mat[i][j-1]) j--;
	 else i--;

}
fprintf(g,"%d\n",k);
for (i=k;i>=1;i--) fprintf(g,"%d ",w[i]);


fclose(f);  
fclose(g);  
return 0;  
}