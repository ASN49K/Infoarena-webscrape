#include<fstream>
using namespace std;
int sir1[1026],sir2[1026];
int rezultat[1026];
int m,n,w=0;
int bun(int i)
{
	int j;
	for (j=0;j<n;j++)
	{
		if (sir2[j]==sir1[i])
		{ 
			rezultat[w]=sir2[j];
			w++;
		}	
		if (sir2[j]==sir1[i]) return 1;
		
	}
return 0;
}



int main()
{
	int nr=0,i;
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	in>>m>>n;
	for (i=0;i<m;i++)
	{
		in>>sir1[i];
	}
	for (i=0;i<n;i++)
	{
		in>>sir2[i];
	}
	for(i=0;i<m;i++)
	{
		if (bun(i)) nr++;
	}
out<<nr<<"\n";
for (i=0;i<w;i++)
{
	out<<rezultat[i]<<" ";
}	
}