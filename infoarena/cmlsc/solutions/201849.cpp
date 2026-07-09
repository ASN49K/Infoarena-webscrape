#include<iostream>
using namespace std;

int a[1025][1025];
int s1[1024];
int s2[1024];
int m, n;

void print_sol(int i, int j)
{
	if(i==0 || j == 0)
		return;
	int max = a[i-1][j];
	bool up = true;
	if(a[i][j-1] > max) 
	{
		max = a[i][j-1];
		up = false;
	}
	if(a[i][j] > max)
	{
		print_sol(i-1, j-1);
		if(i == m && j ==n)
			cout << s1[i] << endl;
		else
			cout << s1[i] << " ";
	} else 
	{
		if(up)
			print_sol(i-1,j);
		else
			print_sol(i, j-1);
	}

}

int main(void)
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	cin >> m >> n;
	for(int i=0;i<m;++i) 
	{
		cin >> s1[i+1];
		a[i][0] = 0;
	}
	for(int i=0;i<n;++i)
	{
		cin >> s2[i+1];
		a[0][i] = 0;
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(s1[i] == s2[j]) 
			{
				a[i][j] = a[i-1][j-1] + 1;
			}else 
			{
				if(a[i-1][j] > a[i][j-1])
				{
					a[i][j] = a[i-1][j];
				}else
				{
					a[i][j] = a[i][j-1];
				}
			}	
		}
	}
	cout << a[m][n] << endl;
	print_sol(m,n);
	return 0;
}