#include<fstream.h>
#define dim 1025
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[dim],b[dim],poz[dim],d[dim],p[dim];
int main()
{int n,m;
f>>n>>m;
int i,j;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=n;i++) f>>b[i];
f.close();
int ok=0;
for(i=1;i<=n;i++)
 {ok=0;
  for(j=1;j<=m;j++)
   if(a[i]==b[j])
    {poz[i]=j;
     ok=1;
     break;
    }
  if(!ok) poz[i]=-1;
 }
int max=0;
d[1]=1;
for(i=1;i<=n;i++)
 {max=0;
  for(j=1;j<i;j++)
    {if(poz[j]!=(-1))
      {if(poz[i]>poz[j])
	 {if(d[j]>=max)
	   {max=d[j];
	    p[i]=j;//j, !poz[j];
	   }
	 }
      }
    }
  d[i]=max+1;
 }
max=0;
for(i=1;i<=n;i++)
 if(d[i]>max) {max=d[i];j=i;}
int max2=max;
g<<max<<'\n';
i=1;
poz[i]=a[j];
while(max>1)
{poz[++i]=a[p[j]];
j=p[j];
max--;
}
for(j=max2;j>=1;j--) g<<poz[j]<<" ";
g<<'\n';
g.close();
return 0;
}
