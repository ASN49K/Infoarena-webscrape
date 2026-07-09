#include <fstream>
using namespace std;
int main ()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int i,n,t;
	long long a,b;
	f>>n;
	for (i=0;i<n;i++){
		f>>a>>b;
		while (a%b!=0){
			t=a%b;
			a=b;
			b=t;
		}
		g<<b<<'\n';
	}
	f.close();
	g.close();
	return 0;
}
