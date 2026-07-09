#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int max(int a,int b);

int main()
{
 FILE * fpin,* fpout;
 fpin=fopen("cmlsc.in","r");
 fpout=fopen("cmlsc.out","w");
 
 int len1,len2;
 fscanf(fpin,"%d",&len1);
 fscanf(fpin,"%d",&len2);
 
 int * sir1=(int *) calloc(len1,sizeof(int));
 int * sir2=(int *) calloc(len2,sizeof(int));
 int i,j;
 
 for (i=0;i<len1;i++) fscanf(fpin,"%d",&sir1[i]);
 for (i=0;i<len2;i++) fscanf(fpin,"%d",&sir2[i]);
 	
 int * * tab=(int * *)calloc(len1+1,sizeof(int *));
 for (i=0;i<len1+1;i++)
 tab[i]=(int *)calloc(len2+1,sizeof(int));
 
 for (i=0;i<len1+1;i++) tab[i][0]=0;
 for (i=0;i<len2+1;i++) tab[0][i]=0;
 
 int maxx=0,maxy=0,val=0;
 for (i=1;i<len1+1;i++)
  for (j=1;j<len2+1;j++)
   {
   	if (sir1[i-1]==sir2[j-1]) tab[i][j]=tab[i-1][j-1]+1; else
   	    tab[i][j]=max(tab[i-1][j],tab[i][j-1]);
    if (tab[i][j]>val) {val=tab[i][j];maxx=i;maxy=j;}
   }
 
 /*for (i=0;i<len1+1;i++)
  {
   for (j=0;j<len2+1;j++)
    printf("%d ",tab[i][j]);
   printf("\n");
  }*/    
  
 int * cmlsc=(int *)calloc(val,sizeof(int));
 i=0;
 while (val!=0)
 {
  if (val==tab[maxx][maxy-1]) maxy--;
  else if (val==tab[maxx-1][maxy]) maxx--;
  else {maxx--;maxy--;cmlsc[i]=sir1[maxx];i++;val--;}	
 }
 
 /*for (j=0;j<i;j++)
  printf("%d ",cmlsc[j]);*/
 fprintf(fpout,"%d\n",i); 
 for (j=i-1;j>=0;j--) fprintf(fpout,"%d ",cmlsc[j]);
  
 return 0;	
}

int max(int a,int b)
{
 if (a>b) return a; else return b;
}
