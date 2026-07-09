#include<stdio.h>
int mat[1030][1030],x[1030],z[1030],i,j,n,m,k=0;



int max (int a,int b)
{
if (a>b)return a;
return b;
}


int main (){

FILE*f=fopen("CMLSC.IN","r");
FILE*g=fopen("CMLSC.OUT","w");


fscanf(f,"%d %d",&n,&m);

for (i=1;i<=n;i++) fscanf(f,"%d",&x[i]);
for (i=1;i<=m;i++) fscanf(f,"%d",&z[i]);


for (i=1;i<=m;i++)
     for (j=1;j<=n;j++)
	  {
	   if (x[j]==z[i]) mat[i][j]=mat[i-1][j-1]+1;
	      else mat[i][j]=max(mat[i-1][j],mat [i][j-1]);
	  }
fprintf(g,"%d\n",mat[m][n]);
for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
	if (mat[i][j]>k) {k=mat[i][j];
			   fprintf(g,"%d ",x[j]);
			  }


fclose(f);
fclose(g);
return 0;
}

