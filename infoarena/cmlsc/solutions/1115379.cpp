#include<cstdio>
#define Nmax 1030
using namespace std;

template<class T>
class cmlsc
{
	T A[Nmax],B[Nmax];
	int D[Nmax][Nmax];
	T R[Nmax];
	int n,m,r;
	public:
	cmlsc() {}
	void citesteN() {scanf("%d",&n);}
	void citesteM() {scanf("%d",&m);}
	void citesteA()
	{
		for(register int i=1;i<=n;i++)
			scanf("%d",&A[i]);
	}
	void citesteB()
	{
		for(register int i=1;i<=m;i++)
			scanf("%d",&B[i]);
	}
	void afisareRaspuns()
	{   
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=m;j++)
				if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
				else D[i][j]=( D[i-1][j]>D[i][j-1] ) ? D[i-1][j] : D[i][j-1];
		
		int r=0;
		for(register int i=n,j=m;i;)
			if( A[i] == B[j] )
				{ R[++r]=A[i]; i--; j--; }
				else if( D[i-1][j] > D[i][j-1] )
						i--;
					 else j--;
		printf("%d\n",D[n][m]);
		for(;r>0;r--)
			printf("%d ",R[r]);
		printf("\n");
	}
};
cmlsc<int> D;
int main()
{
	freopen("cmlsc.in","rt",stdin);
	freopen("cmlsc.out","wt",stdout);
	D.citesteN();
	D.citesteM();
	D.citesteA();
	D.citesteB();
	D.afisareRaspuns();
	return 0;
}
