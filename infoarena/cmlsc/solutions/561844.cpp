#include <cstdio>
#include <vector>
using namespace std;

vector <vector <int> > ab;
int maxim=0,s,n,m;

void test (int a, int b, int q,int aux)
{
	bool fertig=false;
	
	for (int i=a;i<=n;i++)
	{
		for (int j=b;j<=m;j++)
			if (ab[i][0]==ab[0][j] && ab[i][j]==0)
			{
				ab[i][j]=q;
				aux++;
				test (i+1,j+1,q+1,aux);
				fertig=true;
				break;
			}
		if (fertig==true)
			break;
		else
			if (aux>maxim)
			{
				maxim=aux;
				s=i;
			}
	}
}

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	scanf ("%d %d", &n,&m);
	int aux,a=m;
	vector <int> k (1);
	ab.resize (n+1);
	for (int i=0;i<=n;i++)
		ab[i].resize(m+1);
		
	for (int i=1;i<=n;i++)
		scanf ("%d", &ab[i][0]);
	for (int i=1;i<=m;i++)
		scanf ("%d", &ab[0][i]);
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ab[i][j]=0;
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (ab[i][0]==ab[0][j] && ab[i][j]==0)
			{
				ab[i][j]=1;
				test (i+1,j+1,2,1);
			}
				
	printf ("%d\n", maxim);
	aux=maxim;
	for (int i=s;i>0;i--)
	{
		for (int j=a;j>0;j--)
			if (ab[i][j]==aux)
			{
				aux--;
				a=j;
				k.push_back (ab[i][0]);
				break;
			}
		if (k[maxim] && aux==1)
			break;
	}
	
	for (int i=maxim;i>0;i--)
		printf ("%d ", k[i]);
		
}	
