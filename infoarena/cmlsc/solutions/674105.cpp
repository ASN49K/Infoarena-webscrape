#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int M,N,A[1024],B[1024],tab[1024][1024],s[1024],k;
int maxim(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int i,j;
	fin>>M>>N;
	for(i=1;i<=M;i++)
		fin>>A[i];
	for(i=1;i<=N;i++)
		fin>>B[i];
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			if(A[i]==B[j])
				tab[i][j]=tab[i-1][j-1]+1;
			else
				tab[i][j]=maxim(tab[i-1][j],tab[i][j-1]);
	fout<<tab[M][N]<<endl;
	i=M;
	j=N;
	while(i!=0)
	{
		if(A[i]==B[j])
		{
			s[++k]=A[i];
			i--;
			j--;
		}
		else
			if(tab[i-1][j]<tab[i][j-1])
				j--;
			else
				i--;
	}
	for(i=k;i>=1;i--)
		fout<<s[i]<<' ';
	return 0;
}
	