#include<stdio.h>
#define max 1025
int vmax[max],vp[max];
int ivmax,ivp;
int a[max],b[max],m,n;
void functie()
{int i,j,k;
 for(i=1;i<=n;i++)
   { k=0 ;

    for(j=k+1;j<=m;j++)
       {if(a[i]==b[j])
	  {ivp++;
	  vp[ivp]=a[i];
	   k=j;
	  }
       }
       if(ivp>ivmax)
       {for(j=1;j<=ivp;j++)
       vmax[j]=vp[j];
       ivmax=ivp;}
   }
}

int main()
{FILE *f,*ff;
 f=fopen("cmlsc.in","r");
 ff=fopen("cmlsc.out","w");
 int i,j;
fscanf(f,"%d %d",&n,&m);
for(i=1;i<=n;i++)
fscanf(f,"%d",&a[i]);
for(i=1;i<=m;i++)
fscanf(f,"%d",&b[i]);

functie();

fprintf(ff,"%d \n",ivmax);
for(j=1;j<=ivmax;j++)
   fprintf(ff,"%d ",vmax[j]);

fclose(f);
fclose(ff);
return 0;

}


