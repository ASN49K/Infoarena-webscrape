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
 int b[1024];
 int tmp,tmp1=0;
 int max=0;
 for(j=0;j<n;j++)
   {fscanf(f,"%d",&tmp);
    for(i=tmp1;i<m;i++)
       if(tmp==a[i])
         {tmp1=i;
          b[max++]=a[i];

         }
   }
 fclose(f);
 f=fopen("cmlsc.out","w");
 fprintf(f,"%d \n",max);
 for(i=0;i<max;i++)
   fprintf(f,"%d ",b[i]);
   
 fclose(f);
 
 return 0;
}
