#include<fstream>
#define max 1025
ifstream f("cmlsc.in");
ofstream ff("cmlsc.out");
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
{

 int i,j;
f>>n>>m;
for(i=1;i<=n;i++)
f>>a[i];
for(i=1;i<=m;i++)
f>>b[i];

functie();

ff<<ivmax<<"\n";
for(j=1;j<=ivmax;j++)
   ff<<vmax[j]<<" ";

f.close();
ff.close();
return 0;

}