
#include <cstdio>
#include <fstream>

using namespace std;

int main ()
{
	int a,b,t,r;
	ifstream in ("euclid2.in");
	freopen("euclid2.out","w",stdout);
	for(in>>t;t;--t){
		in>>a>>b;
		for(r=a%b;r;r=a%b){
			a=b;
			b=r;
		}
		printf("%d\n",b);
	}
	return 0;}
