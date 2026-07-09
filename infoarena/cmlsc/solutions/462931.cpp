#include<fstream.h>
long a[2000],b[2000],c[1025][1025],n,m;
void cit()
{ifstream fin("cmlsc.in");
  fin>>n>>m;
  long i;
   for(i=1;i<=n;i++)
	   fin>>a[i];
   for(i=1;i<=m;i++)
	   fin>>b[i];
  fin.close();
}
void solve()
{long i,j,max;
 for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++)
		 if(a[i]==b[j])
		  c[i][j]=c[i-1][j-1]+1;
		 else
		 {max=c[i-1][j];
		  if(max<c[i][j-1])
			  max=c[i][j-1];
		  c[i][j]=max;
		 }
}
void afis()
{ofstream fout("cmlsc.out");
  fout<<c[n][m];
 fout.close();
}
int main()
{cit();
 solve();
 afis();
 return 0;
}
