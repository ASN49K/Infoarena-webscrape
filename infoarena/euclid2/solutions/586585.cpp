
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
		r=a%b;
		while(r){
			a=b;
			b=r;
			r=a%b;
		}
		printf("%d\n",b);
	}
	return 0;}
