#include <fstream>
using namespace std;
int main()
{
	ifstream f("nim.in");
	ofstream g("nim.out");
	long long N,x,S,y,i,j;
	f>>N;
	for(i=1;i<=N;i++)
	{	f>>y;
		f>>S;
		for(j=2;j<=y;j++)
		{	f>>x;
			S^=x;
		}
		if(S==0) g<<"NU"<<"\n";
		else g<<"DA"<<"\n";
	}
	f.close();
	g.close();
	return 0;
}