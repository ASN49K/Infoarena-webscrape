#include<fstream>
using namespace std;
int divizor(int a, int b)
{
	int r;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r);
	return a;
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t,a,b;
	f>>t;
	while(t)
	{
		f>>a;
		f>>b;
		g<<divizor(a,b)<<endl;
		t--;
	}
	f.close();
	g.close();
	return 0;
}