
#include <cstdio>
#include <fstream>

using namespace std;

int x,t,n,a,i;

int main ()
{
	
	ifstream f ("nim.in");
	freopen ("nim.out","w",stdout);
	for(f>>t;t;--t){
		f>>n;
		x=0;
		for(i=0;i<n;++i){
			f>>a;
			x^=a;
			}
		if(x)
			printf("DA\n");
		else
			printf("NU\n");
		}
	
	return 0;}
