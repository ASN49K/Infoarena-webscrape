#include<stdio.h>
#define max(a, b) ((a > b) ? a : b)  
#define nmax 1024
int d[nmax][nmax];
int a[1024],b[1024];
int n,m;
int subsir[1024],nr=0;
int main()
{ int i,j;
  
  
  FILE *f,*g;
  f=fopen("cmlsc.in","r");
  g=fopen("cmlsc.out","w");
 fscanf(f,"%d %d",&m,&n);
 for(i=1;i<=m;i++) 
   fscanf(f,"%d",&a[i]);
 for(i=1;i<=n;i++)
   fscanf(f,"%d",&b[i]);
 for(i=1;i<=m;i++)  
   for(j=1;j<=n;j++)
        if (a[i] == b[j])  
              d[i][j] = 1 + d[i-1][j-1];  
        else  
             d[i][j] = max(d[i-1][j], d[i][j-1]);  
  for (i = m, j = n; i; )  
         if (a[i] == b[j])  
             subsir[++nr] = a[i], --i, --j;  
         else if (d[i-1][j] < d[i][j-1])  
             --j;  
         else  
             --i;  
    fprintf(g,"%d\n",nr);
 for(i=nr;i>0;i--)
    {fprintf(g,"%d ",subsir[i]);
    	}   
 fclose(f);
 fclose(g); 
}
