#include <fstream>
#include <iostream>
#include <stack>

#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

int main()
{
	int i, j, n, m;
	short mat[1024][1024];
	short v1[1024], v2[1024];
	
	stack<short> sol;
	int solLength = 0;
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout); 

	cin>>n>>m; // n - linii, m -  coloane
	for(i = 1; i <= n; i++) 
	{
		cin>>v1[i];
		mat[i][1] = 0;		
	}
	for(j = 1; j <= m; j++) 
	{
		cin>>v2[j];
		mat[1][j] = 0;
	}
	
	/* the magic happens here */
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++) 
		{
			if(v1[i] != v2[j]) 
			{
				mat[i][j] = MAX(mat[i - 1][j], mat[i][j - 1]);
			} else {
				mat[i][j] = mat[i - 1][j - 1] + 1;	
			}
		}
	}
	solLength = mat[n][m];
	
	i = n;
	j = m;
	
	while(mat[i][j] != 0) {
		if(mat[i - 1][j - 1] == mat[i][j] - 1) {
			sol.push(v1[i]); // or v2[j]
			i = i - 1;
			j = j - 1;
		} else {
			if(mat[i - 1][j] == MAX(mat[i - 1][j], mat[i][j - 1])) {
				i = i - 1;
			} else if (mat[i][j - 1] == MAX(mat[i - 1][j], mat[i][j - 1])) {
				j = j - 1;
			}
		}	
	}
	
	
	/*
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	*/
	cout<<solLength<<"\n";
	while(!sol.empty()) 
	{
		cout<<sol.top()<<" ";
		sol.pop();
	}
	
	return 0;
}
