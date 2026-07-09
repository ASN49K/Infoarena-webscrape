#define NMAX 1025
#include <vector>
using namespace std;
int Ma[NMAX][NMAX];
vector <int> a,b;
#include <iostream>
#include <algorithm>

vector <int> sol;
vector <int> cmlsc(vector <int> a,vector <int> b)
{
    
    int N=a.size(),M=b.size();
	int i,j;
	
    for(i=1;i<=N;i++)
	{
        for(j=1;j<=M;j++)
		{
            if(a[i-1]==b[j-1]) Ma[i][j]=Ma[i-1][j-1]+1;
            else Ma[i][j]=max(Ma[i-1][j],Ma[i][j-1]);
		}

	}
    
    i=N;j=M;
	while(i && j)
	{
		if(a[i-1]==b[j-1]) {sol.push_back(a[i-1]);i--;j--;}
		else if(Ma[i-1][j]>Ma[i][j-1]) i--;
				else j--;
	}
	int aux;
	for(i=0;i<sol.size()/2;i++)
	{
		aux=sol[i];
		sol[i]=sol[Ma[N][M]-i-1];
		sol[Ma[N][M]-i-1]=aux;
	}
	return sol;
}
#include <fstream>

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int N,M,x,i;
    f>>N>>M;
    for(i=0;i<N;i++)
    {
        f>>x;
        a.push_back(x);
    }
    for(i=0;i<M;i++)
    {
        f>>x;
        b.push_back(x);
    }
    sol=cmlsc(a,b);
	g<<sol.size()<<'\n';
	for(i=0;i<sol.size();i++)
		g<<sol[i]<<' ';
	
}