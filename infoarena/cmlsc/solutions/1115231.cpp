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
		for(register int i=1;i<=n;i++)
			scanf("%d",&B[i]);
	}
	void calcul()
	{
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=m;j++)
				if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
				else D[i][j]=( D[i-1][j]<D[i][j-1] ) ? D[i][j-1] : D[i-1][j];
	}
	int Raspuns()
	{
		return D[n][m];
	}
	void afisareRaspuns()
	{   
		int r=D[n][m];
		for(register int i=n,j=m;r;)
			if( A[i] == B[j] )
				{ R[r]=A[i]; i--; j--; r--; }
				else if( D[i][j-1] > D[i-1][j] )
						j--;
					 else i--;
		for(register int i=1;i<=D[n][m];i++)
			printf("%d ",R[i]);
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
	D.calcul();
	printf("%d\n",D.Raspuns());
	D.afisareRaspuns();
	return 0;
}
