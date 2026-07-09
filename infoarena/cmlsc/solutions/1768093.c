#include<stdio.h>
int v[1025];
int v1[1025];
int rez[1025];
int a[1025][1025];
int main()
{
 int n,m,i,j,f,max,cmax;;
 FILE *fin=fopen("cmlsc.in","r");
 FILE *fout=fopen("cmlsc.out","w");
 fscanf(fin,"%d%d",&n,&m);
 for(i=1;i<=n;i++)
     fscanf(fin,"%d",&v[i]);
 for(j=1;j<=m;j++)
     fscanf(fin,"%d",&v1[j]);
 max=0;
 for(i=1;i<=n;i++)
    {
     for(j=1;j<=m;j++)
        {
         if(v[i]==v1[j])
             a[i][j]=a[i-1][j-1]+1;
         else
            {
             if(a[i-1][j]>a[i][j-1])
                a[i][j]=a[i-1][j];
             else
                a[i][j]=a[i][j-1];
            }
         if(a[i][j]>max)
             max=a[i][j];
        }
    }
 i=n;
 j=m;
 cmax=max;
 f=0;
 while(i>=1 && j>=1)
      {
       if(v[i]==v1[j])
          {
           rez[++f]=v[i];
           i--;
           j--;
          }
       else
          {
           if(a[i][j-1]>a[i-1][j])
              j--;
           else
              i--;
          }
       max--;
      }
 fprintf(fout,"%d\n",cmax);
 for(i=f;i>=1;i--)
     fprintf(fout,"%d ",rez[i]);
 fprintf(fout,"\n");
return 0;
}

