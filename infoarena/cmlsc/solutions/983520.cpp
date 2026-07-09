using namespace std;
#include<fstream>
#include<algorithm>
ifstream eu("cmlsc.in");
ofstream tu("cmlsc.out");
#define Nmax 1024
int M,N,A[Nmax],B[Nmax],DP[Nmax][Nmax],Cmlsc[Nmax],k;
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
				Cmlsc[++k]=A[i];
				i--;j--;
			}
			else
				if(DP[i-1][j]<DP[i][j-1])
					j--;
				else
					i--;
		}
	tu<<k<<"\n";
	for(i=k;i>0;i--)
		tu<<Cmlsc[i]<<" ";
	return 0;
}
