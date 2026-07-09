#include <stdio.h>
#define NM 1025
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int a[NM],b[NM],n,m;
int pd[NM][NM],v[NM][NM];//-1=i--; 1=j--; 0=i--,j--
int main()
{ int i,j;
  fscanf(f,"%d %d",&n,&m);
  for (i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
  for (i=1;i<=m;i++) fscanf(f,"%d",&b[i]);
  fclose(f);
  for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
		{ pd[i][j]=pd[i-1][j];
		  v[i][j]=-1;
		  if (pd[i][j-1]>pd[i][j])
			{ pd[i][j]=pd[i][j-1];
			  v[i][j]=1;
			}
		  if ((pd[i-1][j-1]+1>pd[i][j])&&(a[i]==b[j]))
			{ pd[i][j]=pd[i-1][j-1]+1;
			  v[i][j]=0;
			}
		}
  fprintf(g,"%d\n",pd[n][m]);
  i=n;j=m;
  int k=0;
  int x[NM];
  while (i>0&&j>0)
	 switch(v[i][j])
		{ case -1: i--;break;
		  case  1: j--;break;
		  case  0: x[++k]=a[i];
			   i--;j--;
		}
  for (i=k;i>=1;i--) fprintf(g,"%d ",x[i]);
  fclose(g);
  return 0;
}