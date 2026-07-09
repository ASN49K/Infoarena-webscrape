#include<iostream>
#include<fstream>
#define NMax 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,MAX,sol[NMax],temp[NMax],A[NMax],B[NMax];
void input()
{
	int i;
	f>>N>>M;
	for(i=1;i<=N;i++)
		f>>A[i];
	for(i=1;i<=M;i++)
		f>>B[i];
}
void ouput()
{
	g<<MAX<<'\n';
	for(int i=1;i<=MAX;i++)
		g<<sol[i]<<' ';
	
}
bool check(int k)
{
	int i, j = 1;
	for (i = 1; i <= k && j <= M; i++)
		for (; j <= M && B[j] != temp[i]; ++j);
	return j <= M;
}
void generate(int t,int k)
{ 
	for(int i=t;i<=N;i++)
	{	temp[k]=A[i];
		generate(i+1,k+1);
	}
	k=k-1;
	if(check(k)==1)
		if(k>MAX)
		{	MAX=k;
			for(int j=1;j<=k;j++)
				sol[j]=temp[j];
		}
}
int main()
{
	input();
	generate(1,1);
	ouput();
	return 0;
}
