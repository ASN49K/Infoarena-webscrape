#include<fstream>
using namespace std;
int main()
{
	int n;
	unsigned a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	while(f>>a&&f>>b)
	{
	    do{
			r=a%b;
			a=b;
			b=r;
		}while(r);
		g<<a<<endl;
	}
	f.close();
	g.close();
}

