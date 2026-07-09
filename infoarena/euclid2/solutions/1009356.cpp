#include<fstream>
using namespace std;
int cmmdc(int x,int y)
{
	if(x==0||y==0)
		return x+y;
	if(x>y)
		return cmmdc(x%y,y);
	if(x<=y)
		return cmmdc(x,y%x);

}
int main(void)
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int T,x,y;
	f>>T;
	for(int i=1;i<=T;i++)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<"\n";
	}
}