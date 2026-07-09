#include<fstream.h>
#define dim 1025//1000//5
#define dim2 1050000
int a[dim],b[dim],p[dim],b2[dim];
int (*c)[dim2]=new int [dim2][dim2];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{int n,m;
f>>n>>m;
int i,j,cont=0;
for(i=1;i<=n;i++) f>>a[i];
for(j=1;j<=m;j++) f>>b[j];
f.close();

//completez c
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  {if(a[i]==b[j])
    {c[++cont][0]=i;
     c[cont][1]=j;
    }
  }

//cel mai lg subs. crescator
int max,max2;
b[1]=1;
for(i=2;i<=cont;i++)
 {max=0;j=0;
  for(j=1;j<i;j++)
   {if((c[j][0]<c[i][0])&&(c[j][1]<c[i][1])&&(b[j]>max)) {max=b[j];m=j;}
   }
  p[i]=m;
  b[i]=max+1;
 }
max=0;
for(i=1;i<=cont;i++)
 if(b[i]>max)
  {max=b[i];
   m=i;
  }
g<<max<<'\n';
i=1;
b2[i]=a[c[m][0]];
m=p[m];
max2=max;
max=max-1;
while(max)
{i++;
 b2[i]=a[c[m][0]];
 m=p[m];
 max--;
}
for(i=max2;i>=1;i--) g<<b2[i]<<" ";
//cout<<b2[1]<<" "<<b2[2]<<" ";
g<<'\n';
g.close();
return 0;
}
