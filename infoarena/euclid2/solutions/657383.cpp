#include <fstream>
using namespace std;
int main() {
	FILE *f;
	f=fopen("euclid2.in","r");
	ofstream g("euclid2.out");
	int n,a,b,r,i;
	fscanf(f,"%d",&n);
	for (i=1; i<=n; i++) {
		fscanf(f,"%d%d",&a,&b);
		while (b) {
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<'\n';
	}
	g.close();
	return 0;
}
