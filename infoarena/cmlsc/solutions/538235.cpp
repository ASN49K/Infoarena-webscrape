#include <fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m, A[1025], B[1025], M[1025][1025],maximus=0,vmax[1025];

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

void afismatrice()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			g<<M[i][j]<<" ";
		g<<"\n";
	}
}

int main()
{
	int i,j;
	//Citim dimensiunile vectorilor si vectorii;
	f>>n>>m;
	//Citim vectorul A
	for(i=1;i<=n;i++)
		f>>A[i];
	//Citim vectorul B
	for(i=1;i<=m;i++)
		f>>B[i];
	//Initializam matricea cu 0
	for(i=1;i<=n+1;i++)
		for(j=1;j<=m+1;j++)
			M[i][j]=0;	
	M[n][m]=1;
	//Incepem parcurgerea matricei , din coltul dreapta jos, matricea fiind nxm.
	for(i=n;i>=1;i--)
		for(j=m;j>=1;j--)
			//Daca gasim un termen din vectorul A , identic cu un termen din Vectorul B, punem pe pozitia M[i][j] , cea mai 
			//mare valoare vecina +1;
			if(A[i] == B[j])
			{				
				M[i][j] = max(M[i+1][j],M[i][j+1]) + 1;
				if(vmax[maximus]!=A[i])
				{
					maximus++;
					vmax[maximus]=A[i];				
				}
			}
			//Daca nu gasim un termen identic, punem in matrice pe pozitia [i][j] cea mai mare valoare vecina.
			else
				M[i][j] = max(M[i+1][j],M[i][j+1]);
	afismatrice();
	g<<"\n";
	g<<maximus<<"\n";
	//maximus a retinut numarul termenilor in comun , iar termenii in comun sunt memorati in vectorul vmax.
	for(int i = maximus ; i>=1 ; i--)
		g<<vmax[i]<<" ";
	f.close();
	g.close();
	return 0;
}