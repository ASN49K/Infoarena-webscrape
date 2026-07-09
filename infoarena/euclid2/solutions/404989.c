#include<fstream>
struct euclid
{int x,y;
};
using namespace std;
euclid a[100];
int main(void)
{
	int T,i,j,t=0;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for(i=1;i<=T;i++)
		f>>a[i].x>>a[i].y;
	for(i=1;i<=T;i++)
	{
		t=0;
		for(j=a[i].x;j>=1&&t==0;j--)
			if(a[i].x%j==0&&a[i].y%j==0)
				{g<<j<<'\n';t=1;}
	}
	return 1;
}