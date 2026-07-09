#include <fstream>
#include <stdlib.h>
#define maxN 1025
using namespace std;
int n,m;
int maxSize;
int x[maxN],y[maxN],sol[maxN],setSol[maxN];
bool foundSol;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void getInput()
{
	in>>n>>m;

	for(int i=1;i<=n;i++)
	{
		in>>x[i];
	}

	for(int i=1;i<=m;i++)
	{
		in>>y[i];
	}

}

void saveResult()
{
    for(int i=1;i<=maxSize;i++)
    {
        sol[i] = setSol[i];
    }
}
void bkt(int k,int pozX,int pozY)
{
	if(foundSol==true)
	{
		return;
	}

	if(k==maxSize)
	{
	    foundSol = true;
	    saveResult();
	}
	else
	{
		for(int i=pozX+1;i<=n && foundSol == false;i++)
		{
			for(int j=pozY+1;j<=m && foundSol == false;j++)
			{
				if(x[i]==y[j])
				{
					setSol[k+1]=x[i];
					bkt(k+1,i,j);
				}
			}
		}
	}
}

void solve()
{
	for(int i=1;i<=m;i++)
	{
		maxSize = i;
		foundSol=false;
		bkt(0,0,0);
		if(foundSol == false)
		{
			maxSize--;
			return;
		}
	}
}

void write()
{
	out<<maxSize<<"\n";
	for(int i=1;i<=maxSize;i++)
	{
		out<<sol[i]<<" ";
	}
}

int main()
{
	getInput();
	solve();
	write();
}
