#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,x,y,i,r;

int cmmdc(int a,int b)
{
	int r=0;
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return r;
}

int main(){
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		r=0;
		r=x%y;
		while(r)
		{
			x=y;
			y=r;
			r=x%y;
		}
		g<<y<<"\n";
	}
	
	f.close();
	g.close();
	return 0;
}