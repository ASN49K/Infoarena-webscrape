#include <string.h>
#include <stdio.h>
#define N 1025
int mat[N][N];
int sir1[N];
int sir2[N];

int main ()
{FILE *f,*fout;
 int m,n,i,j,k;
 f=fopen("cmlsc.in","r");
 fout=fopen("cmlsc.out","w");
 fscanf(f,"%d%d",&n,&m);

 for (i=1;i<=n;i++)
  fscanf(f,"%d",&sir1[i]);

 for (i=1;i<=m;i++)
  fscanf(f,"%d",&sir2[i]);

 memset(mat,0,sizeof(mat));
 for (i=1;i<=n;i++)
 {for (j=1;j<=m;j++)
  {if(sir1[i]==sir2[j])
   {mat[i][j]=mat[i-1][j-1]+1;}
   else 
   {if(mat[i-1][j]>mat[i][j-1])
     mat[i][j]=mat[i-1][j];
    else
     mat[i][j]=mat[i][j-1];
   } 
  }
 }
 
 fprintf(fout,"%d\n",mat[n][m]);
 for (i=n;i>=1;)
 {for (j=m;j>=1;)
  {fprintf(fout,"%d ",sir1[i]);
   i--;j--;   
   while(mat[i][j]==mat[i-1][j])
    i--;
   while(mat[i][j]==mat[i][j-1])
    j--;
  }
 }
 return 0;
}