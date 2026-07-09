#include<fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x,y,v1[1025],v2[1025],i,j,a[1025][1025],v3[1025],poz;
int main ()
{f>>x>>y;
 for (i=1;i<=x;i++) f>>v1[i];
 for (i=1;i<=y;i++) f>>v2[i];
 for (i=1;i<=x;i++)
	for (j=1;j<=y;j++)
		 if (v1[i]==v2[j]) {a[i][j]=a[i-1][j-1]+1;}
		 else if (a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
				else a[i][j]=a[i][j-1];
 i=x;j=y;
 g<<a[x][y]<<'\n';
 while (i && j)
	{if (v1[i]==v2[j]) {v3[poz]=v1[i];i--;j--;poz++;}
	 else if (a[i-1][j]>a[i][j-1]) i--;
	 else j--;}
 for (i=poz-1;i>=0;i--) g<<v3[i]<<" ";
 return 0;
}


