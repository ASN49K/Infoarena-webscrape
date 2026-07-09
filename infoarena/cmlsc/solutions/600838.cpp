#include<iostream>
#include<fstream>
using namespace std;
int v[20],w[20],m,n,sol[20],t,beta[20];
ifstream f("input.in");

void input()
{
	int i;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>v[i];
	for(i=1;i<=n;i++)
		f>>w[i];
}
void check(int k)
{
	k-=1;
	if(k>t)
	{	t=k;
		for(int i=1;i<=t;i++)
			sol[i]=beta[i];
	}

}
void back(int k,int l,int p)
{
	int i,j;
	for(i=l+1;i<=n;i++)
		for(j=p+1;j<=m;j++)
			if(v[i]==w[j])
			{	beta[k]=v[i];
				back(k+1,i,j);
			}
	check(k);
}
void output ()
{
	for(int i=1;i<=t;i++)
		cout<<sol[i]<<' ';
}
int main()
{
	input();
	back(1,0,0);
	output();
	return 0;
}