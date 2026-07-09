#include<fstream>

using namespace std;
unsigned c[1024];
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	unsigned a[1024],b[1024];
	int M,N,i,j;
	int k=1;
	f>>N>>M;
	for(i = 1;i <= N;i++)
		f>>a[i];
	for(i = 1;i <= M;i++)
		f>>b[i];
	for(i = 1;i <= N;i++)
	{
		if(c[k]>a[i])
			continue;
		for(j = 1;j <= M;j++)
		{
			if(a[i]==b[j])
			{
				c[k++] = a[i];
				break;
			}
		}
	}
	g<<k-1<<'\n';
	for(i = 1;i <= k-1;i++)
		g<<c[i]<<" ";
	f.close();
	g.close();
	return 0;
}