#include<fstream>
struct euclid
{int x,y;
};
using namespace std;
euclid a[100];
int main(void)
{
	int n,i,j,max=0,t=0;
	ifstream f("euclid.in");
	ofstream g("euclid.out");
	f>>n;
	for(i=1;i<=n;i++)
		f>>a[i].x>>a[i].y;
	for(i=1;i<=n;i++)
	{
		t=0;
		for(j=a[i].x;j>=1&&t==0;j--)
			if(a[i].x%j==0&&a[i].y%j==0)
				{g<<j<<'\n';t=1;}
	}
	return 1;
}