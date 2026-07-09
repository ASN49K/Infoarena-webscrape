#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

int main()
  {
   FILE *f=fopen("cmlsc.in","rt");
   FILE *g=fopen("cmlsc.out","wt");
   int n,m,i,j,ls=0;
   int a[1024],b[1024],sir[1024];
   int d[1024][1024];
   
   fscanf(f,"%i%i",&n,&m);
  
   for(i=1;i<=n;i++) fscanf(f,"%i",&a[i]);
   for(i=1;i<=m;i++) fscanf(f,"%i",&b[i]);
   
   for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
        if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
          else d[i][j]=MAX(d[i-1][j],d[i][j-1]);
   
   i=n;
   j=m;
   while (i)
     {
      if (a[i]==b[j])
         {
          ls++;
          sir[ls]=a[i];
          i--;
          j--;
         }
      else if (d[i-1][j]<d[i][j-1]) j--;
              else i--;   
     }
   fprintf(g,"%i\n",ls);
   for(i=ls;i;i--)
       fprintf(g,"%i ",sir[ls]);
   fclose(f);
   fclose(g);
   return 0;
  }
  
