#include<cstdio>

#define maxim(a,b)((a>b) ? a:b )
#define for(i,a,b) for(i=a;i<=b;i++)
#define NMax 1024

FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");

using namespace std;
 
int m,n,A[NMax],B[NMax],bst,v[NMax],DP[NMax][NMax];
void read()
{
	int i;
	 fscanf(f,"%d%d",&m,&n);
	for(i,1,m)
		fscanf(f,"%d",&A[i]);
	for(i,1,n)
		fscanf(f,"%d",&B[i]);
}
void solve()
{
	int i,j;
	for(i,1,m)
		for(j,1,n)
			if(A[i]==B[j])
				DP[i][j]=1+DP[i-1][j-1];
			else
				DP[i][j]=maxim(DP[i][j-1],DP[i-1][j]);
			
	for(i=m,j=n;i;)
		if( A[i] == B[j] )
		{
			v[++bst]=A[i];--i;--j;
		}
		else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
	
}
void write()
{
	int i;
	 fprintf(g,"%d\n", bst);
    for (i = bst; i; --i)
        fprintf(g,"%d ", v[i]);
}
int main()
{
	
	read();
	solve();
	write();
	return 0;
}
