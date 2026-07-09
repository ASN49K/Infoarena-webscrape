#include <fstream.h>
#include <stdio.h>
FILE *g2=fopen("cmlsc.out","w");;
ifstream f("cmlsc.in");
int n, m, a[1025], b[1025], sc[1025][1025], i, j, i1, j1, max1, d[1025], k=0, sw;

int max(int l, int c)
{max1=0;
 for (i1=0; i1<=l; i1++)
	for (j1=0; j1<=c; j1++)
		if (max1<sc[i1][j1])
			max1=sc[i1][j1];
 return max1;
}

void vec(int maxim, int l, int c)
{sw=0;
 for (register int i=l; i>=1;)
	for (register int j=c; j>=1)
		if (sc[i-1][j]==sc[i][j-1])
			{d[++k]=b[i];
 			 i--;
			 j--;
			}
		else
			if (sc[i-1][j]<sc[i][j-1])
				j--;
			else
				i--;
}

void tip()
{for (register int i=k; i>=1; i--)
	{fprintf(g2,"%d ",d[i]);
//     cout<<d[i]<<' ';
	}
// cout<<endl;
}


int main()
{f>>n>>m;
 for (i=1; i<=n; i++)
	f>>a[i],sc[0][i]=0;
 for (i=1; i<=m; i++)
	f>>b[i],sc[i][0]=0;
 f.close();
 for (i=1; i<=m; i++)
	for (j=1; j<=n; j++)
		if (b[i]==a[j])
			sc[i][j]=max(i-1,j-1)+1;
 int p=max(m,n);
 fprintf(g2,"%d\n",p);
 vec(p,m,n);
 tip();
 fcloseall();
 return 0;
}