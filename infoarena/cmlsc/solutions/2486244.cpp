//#include "pch.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
int v[1005][1005];
int c[1005][1005];
int b[1005][1005];
int ans[1005];
int n,m;
int fosz;
int main()
{
	f >> n >> m;;
	for (size_t i = 1; i <= n; i++)
	{
		f >> v[1][i];
	}
	for (size_t i = 1; i <= m; i++)
	{
		f >> v[2][i];
	}


	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= m; j++)
		{
			if (v[1][i]==v[2][j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;//i-1 j-1;
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 2; //i-1 j
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = 3; // i j-1
				}
			}
		}
	}
	
	int i = n;
	int j = m;
	
	while (b[i][j])
	{
		if (b[i][j] == 3)
		{
			j--;
			continue;
		}
		if (b[i][j] == 2)
		{
			
			i--;
			continue;
		}
		if (b[i][j] == 1)
		{
			ans[fosz++] = v[2][j];
			i--;
			j--;
			continue;
		}
		
	}
	o<< fosz << "\n";
	for (int i = fosz+1; i >= 0; i--)
	{	
		if(ans[i])
		o << ans[i] << " ";
	}
}










