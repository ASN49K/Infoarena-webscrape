#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,d,im,t,i,r;
int main()
{
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
	if(a>b) {d=a; im=b;}
	else {d=b; im=a;}
	r=d%im;
	while(r>0)
	{
		d=im;
		im=r;
		r=d%im;
	}
	g<<im<<'\n';
	}
	return 0;
}
