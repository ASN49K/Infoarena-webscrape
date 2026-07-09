#include<fstream>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short a[1025], b[1025], t[1025][1025], v[1025];
int m, n, k;
int main()
{f>>m>>n;
 for(int i=1;i<=m;i++) f>>a[i];
 for(int i=1;i<=m;i++) f>>b[i];
 for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
		 if(a[i]==b[j]) t[i][j]=t[i-1][j-1]+1;
	     else t[i][j]=maxim(t[i][j-1], t[i-1][j]);
 g<<t[m][n]<<"\n";
 int i=m; int j=n;
 while(i>0 && j>0)
	{if(a[i]==b[j]) {v[++k]=a[i]; i--; j--;}
	 else if(t[i][j]==t[i-1][j]) i--;
	      else if(t[i][j]==t[i][j-1]) j--;
	}
 for(int i=k;i>=1;i--) g<<v[i]<<" ";
 g<<"\n";
 g.close();
 return 0;
} 