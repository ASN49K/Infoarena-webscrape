#include<fstream.h>
long a[2000],b[2000],c[1025][1025],n,m,d[1025][1025];
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
		  {c[i][j]=c[i-1][j-1]+1;
		   d[i][j]=3;
		  }
		 else
		 {max=c[i-1][j];
		  d[i][j]=1;
		  if(max<c[i][j-1])
			{  max=c[i][j-1];
		       d[i][j]=2;
			}
		  c[i][j]=max;
		 }
}
ofstream fout("cmlsc.out");
void drum(long i,long j)
{if(c[i][j]>0)
	if(a[i]==b[j])
	{drum(i-1,j-1);
	 fout<<a[i]<<" ";
	}
	else
		if(d[i][j]==1)
			drum(i-1,j);
		else
			drum(i,j-1);
}
void afis()
{
  fout<<c[n][m]<<'\n';
  drum(n,m);
 fout.close();
}
int main()
{cit();
 solve();
 afis();
 
 return 0;
}
