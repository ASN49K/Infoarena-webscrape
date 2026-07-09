#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
int v[1025][1025];
int a[1025];
int b[1025];
vector<int> subsir;
int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	ifstream input("cmlsc.in");
	ofstream output("cmlsc.out");
	int n,m;
	input>>n>>m;
	for(int i=1;i<=n;i++)
		input>>a[i];
	for(int i=1;i<=m;i++)
		input>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				v[i][j]=v[i-1][j-1]+1;
			}
			else
			{
				v[i][j]=max(v[i][j-1],v[i-1][j]);
			}
		}
	}
	
	output<<v[n][m]<<endl;
	while(n!=0 && m!=0)
	{
		if(v[n-1][m-1] < v[n][m])
		{
			subsir.push_back(a[n]);
			n--;m--;
		}
		else
		{
			n--;
		}
	}
	for(auto it=subsir.rbegin();it!=subsir.rend();it++)
		output<<*it<<"";
	
	return 0;
}