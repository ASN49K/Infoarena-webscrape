#include <fstream>
#define NMax 1025
#define maxim(a,b) ((a>=b)? a:b)
using namespace std;

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], best;

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");	
	fin>>M>>N;
	int i,j;
	for (i=1;i<=M;i++)
		fin>>A[i];
	for (i=1;i<=N;i++)
		fin>>B[i];
	
	for (i=1;i<=M;i++)
		for (j=1;j<=N;j++)
			if (A[i]==B[j])
				D[i][j]=D[i-1][j-1]+1;
			else
				D[i][j]=maxim(D[i-1][j],D[i][j-1]);
	
	best=0,i=M,j=N;
	while (i)
		if(A[i]==B[j])
			sir[++best]=A[i],i--,j--;
		else
			if(D[i-1][j]<D[i][j-1])
				j--;
			else
				i--;
			
	fout<<best<<"\n";
	for(i=1;i<=best;i++)
		fout<<sir[i]<<" ";
	fin.close();
	fout.close();
	return 0;
}
