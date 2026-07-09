#include <stdio.h>
#define NM 1025
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int a[NM],b[NM],n,m;
int pd[NM][NM];//-1=i--; 1=j--; 0=i--,j--
int main()
{ int i,j;
  fscanf(f,"%d %d",&n,&m);
  for (i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
  for (i=1;i<=m;i++) fscanf(f,"%d",&b[i]);
  fclose(f);
  for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
		{ pd[i][j]=pd[i-1][j];
		  if (pd[i][j-1]>pd[i][j])
			{ pd[i][j]=pd[i][j-1];
			}
		  if ((pd[i-1][j-1]+1>pd[i][j])&&(a[i]==b[j]))
			{ pd[i][j]=pd[i-1][j-1]+1;
			}
		}
  fprintf(g,"%d\n",pd[n][m]);
  i=n;j=m;
  int k=0;
  int x[NM];
  while (i>0&&j>0)
	if (a[i]==b[j])
		{ x[++k]=a[i];i--;j--;}
	else if (pd[i][j-1]>pd[i-1][j]) j--;
		else i--;
  for (i=k;i>=1;i--) fprintf(g,"%d ",x[i]);
  fclose(g);
  return 0;
}
