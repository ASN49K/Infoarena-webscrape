#include <fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m, A[1025], B[1025], M[1026][1026],maximus=0,ii,jj;

int max(int a,int b)
{
	if(a>b)return a;
	return b;
}

int main()
{
	int i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>A[i];
	for(i=1;i<=m;i++)
		f>>B[i];
	
	for(i=n;i>=1;i--)
		for(j=m;j>=1;j--)
			{if(A[i] == B[j]) 
				  M[i][j] = 1+ M[i+1][j+1];
			 else
				M[i][j] = max(M[i+1][j],M[i][j+1]);
			
			 if(M[i][j]>maximus) maximus=M[i][j],ii=i,jj=j;
			}
			g<<maximus<<"\n";
			
	while(maximus)
	{ if(A[ii]==B[jj]) {g<<A[ii]<<' ';ii++,jj++,maximus--;}
	    else
			if(M[ii+1][jj]>M[ii][jj+1]) ii++;
		         else jj++;
	}
	   
	
	f.close();
	g.close();
	return 0;
}
