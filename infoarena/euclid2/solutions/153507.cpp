#include<fstream.h>
#define dim 401
int t,n,m,x,y;
unsigned long (*a)[dim]=new unsigned long [dim][dim];
//unsigned long a[dim][dim];
unsigned long cmmdc(unsigned long p,unsigned long q)
{unsigned long r;
 do
  {r=p%q;
   p=q;
   q=r;
  }
 while(r);
return p;
}
int main()
{ifstream f("euclid.in");
 ofstream g("euclid.out");
 int i,j,k,l,kk=1;
 f>>t;
 unsigned long max=1,c,aux1,aux2,cc;
 while(t)
  {max=1;
   f>>n>>m>>x>>y;
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     f>>a[i][j];
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     {aux1=i+x-1;
      aux2=j+y-1;
      c=a[i][j];
      if((aux1<=n)&&(aux2<=m))
       {for(k=i;k<=aux1;k++)
	 for(l=j;l<=aux2;l++)
	  {cc=c;
	   c=cmmdc(a[k][l],cc);
	  }
	if(c>max) max=c;
       }
     }
   g<<"Case #"<<kk<<": "<<max<<'\n';
   kk++;
   t--;
  }
 f.close();
 g.close();
return 0;
}