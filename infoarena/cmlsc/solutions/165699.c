#include<stdio.h>
int main()
{int a[1024];
 int m,n;
 int i,j;
 FILE *f=fopen("cmlsc.in","r");
 fscanf(f,"%d %d",&m,&n);
 for(i=0;i<m;i++)
    {fscanf(f,"%d",&a[i]);
    }
 int b[1024],c[1024];
 int tmp,tmp1=0;
 int max=0;
 for(j=0;j<n;j++)
   {fscanf(f,"%d",&b[j]);

   }
 fclose(f);
 for(i=0;i<n;i++)
    for(j=tmp1;j<m;j++)
       {if(b[i]==a[j])
          {c[max++]=a[j];
           tmp1=j;
           break;
          }
       }
 f=fopen("cmlsc.out","w");
 fprintf(f,"%d \n",max);
 for(i=0;i<max;i++)
   fprintf(f,"%d ",c[i]);
   
 fclose(f);
 
 return 0;
}
