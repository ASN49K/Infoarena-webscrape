#include<stdio.h>

#define max 1025

FILE *fin=fopen("cmlsc.in","r");
FILE *fout=fopen("cmlsc.out","w");
int n,m,a[max],b[max],c[max][max],s[max],k;

int main()
{
    int i,j;
    fscanf(fin,"%d %d",&n,&m);
    for(i=1;i<=n;i++)
      fscanf(fin,"%d",&a[i]);
    for(i=1;i<=m;i++)
      fscanf(fin,"%d",&b[i]);
      
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(a[i]==b[j])
         c[i][j]=c[i-1][j-1]+1;
        else
          c[i][j]=((c[i-1][j]>c[i][j-1]) ? c[i-1][j] : c[i][j-1]);
    
    k=1;      
    for(i=n,j=m;i;)
      if(a[i]==b[j])
        s[k]=a[i],i--,j--,k++;
      else
        {
          if(c[i-1][j]>c[i][j-1])
            i--;
          else
            j--;
        }
    
    fprintf(fout,"%d\n",c[n][m]);  
    for(i=k-1;i>0;i--)
      fprintf(fout,"%d ",s[i]);
    fprintf(fout,"\n");
    
    fclose(fin);
    fclose(fout);
    return 0;
}
