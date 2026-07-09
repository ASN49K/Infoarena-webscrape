#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int max(int a,int b){
    return a>b?a:b;
}

void back(FILE* fp,int**a,int*s1,int*s2,int i,int j){
   if(i>0&&j>0)
   if(*(s1+i-1)==*(s2+j-1)){
    back(fp,a,s1,s2,i-1,j-1);
    fprintf(fp,"%d ",*(s1+i-1));
   }
   else
      if(*(*(a+i)+j-1)>*(*(a+i-1)+j))
          back(fp,a,s1,s2,i,j-1);
      else
          back(fp,a,s1,s2,i-1,j);
}

int main()
{
   FILE *fp;
   int**a;
   int i;
   int j;
   int*s1;
   int*s2;
   int l_s1;
   int l_s2;
   fp=fopen("cmlsc.in","r");
   fscanf(fp,"%d %d",&l_s1,&l_s2);
   s1=(int*)malloc(sizeof(int)*l_s1);
   s2=(int*)malloc(sizeof(int)*l_s2);
   for(i=0;i<l_s1;i++)
      fscanf(fp,"%d",&*(s1+i));
   for(i=0;i<l_s2;i++)
      fscanf(fp,"%d",&*(s2+i));
   fclose(fp);
   a=(int**)malloc(sizeof(int*)*(l_s1+1));
   for(i=0;i<=l_s1;i++)
      *(a+i)=(int*)calloc(l_s2+1,sizeof(int));
   for(i=1;i<=l_s1;i++){
      for(j=1;j<=l_s2;j++)
           if(*(s1+i-1)==*(s2+j-1))
              *(*(a+i)+j)=*(*(a+i-1)+j-1)+1;
           else
              *(*(a+i)+j)=max(*(*(a+i)+j-1),*(*(a+i-1)+j));
   }
   fp=fopen("cmlsc.out","w");
   fprintf(fp,"%d\n",*(*(a+l_s1)+l_s2));
   back(fp,a,s1,s2,l_s1,l_s2);
   fclose(fp);
   return 0;
}
