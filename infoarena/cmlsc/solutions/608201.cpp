#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,MAX=0,sol[100],temp[100],A[100],B[100];
void input()
{
	int i;
	f>>N;
	f>>M;
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
	int j,p=1;
	for(int i=1;i<=k;i++)
		for(j=p;j<=M;j++)
		{	if(temp[i]==B[j])
			{	p=j+1;
				j=M+1;
			}
			else
				if(j==M)
					return 0;
		}
	return 1;
}
void generate(int t,int k)
{ 
	for(int i=t;i<=N;i++)
	{	temp[k]=A[i];
		generate(i+1,k+1);
	}
	k=k-1;
	//for(int j=1;j<=k;j++)
		//cout<<temp[j]<<' ';
	//cout<<endl;
	if(k>MAX)
		if(check(k)==1)
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