using namespace std;
#include<fstream>
#define Nmax 1024
#include<algorithm>
ifstream eu("cmlsc.in");
ofstream tu("cmlsc.out");
int M,N,DP[Nmax][Nmax],A[Nmax],B[Nmax],Sol[Nmax],K;
int main()
{
	int i,j;
	eu>>M>>N;
	for(i=1;i<=M;i++)
		eu>>A[i];
	for(i=1;i<=N;i++)
		eu>>B[i];
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			if(A[i]==B[j])
				DP[i][j]=DP[i-1][j-1]+1;
			else
				DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
		i=M;j=N;
		while(i&&j)
		{
			if(A[i]==B[j])
			{
				Sol[++K]=A[i];
				i--;j--;
			}
			else
				if(DP[i-1][j]<DP[i][j-1])
					j--;
				else
					i--;
		}
	tu<<K<<"\n";
	for(i=K;i>0;i--)
		tu<<Sol[i]<<" ";
	return 0;
}
