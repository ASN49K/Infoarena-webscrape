#include<fstream>
using namespace std;
int x[2001],y[2001],lcs[2001][2001],a[1200];
int main ()
{
	int n,k,i,j,ok,m;
	
	ifstream fin("cmlsc.in");
	
	fin>>n>>k;
	for(i=1; i<=n; i++)
		fin>>x[i];
	
	for(i=1; i<=k; i++)
		fin>>y[i];
	
	fin.close();
	
	ofstream fout("cmlsc.out");
	
	// initializarile matricei:
	
//	{
	
	
	for(j=1; j<=k; j++)
	{
		ok=1;
		
		if(x[1]==y[j])
			ok=0;	
		
		if(ok==0)
			lcs[1][j]=1;
		else lcs[1][j]=0;
	}
	
	
	for(i=1; i<=n; i++)
	{
		ok=1;
		
		if(y[1]==x[i])
			ok=0;
		
		if(ok==0)
		lcs[i][1]=1;
		else lcs[i][1]=0;
	}
	
	
//	}
	
	for(i=2; i<=n; i++)
	{
		for(j=2; j<=k; j++)
			if( x[i] == y[j] )
				lcs[i][j] = max(lcs[i-1][j-1]+1,max( lcs[i-1][j],lcs[i][j-1] ));
			else
			{
				lcs[i][j] = max( lcs[i-1][j],lcs[i][j-1] );
			}
	}
	
	// Solutia:
	
	fout<<lcs[n][k]<<"\n";
	
	i=n;
	j=k;
	m=0;
	
	while(lcs[i][j]!=0)
	{
		if( x[i]!=y[j] )
		{
			if(lcs[i-1][j] > lcs[i][j-1])
				i--;
			else j--;
		}
		else
		{
			a[m++]=x[i];
			i--;
			j--;
		}
	}
	
	for(i=m-1; i>=0; i--)
		fout<<a[i]<<" ";
	
	fout.close();	
	
	return 0;
}
