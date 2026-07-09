#include<fstream>
using namespace std;
int main() {
	int a,b,c,r,t,i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=1;i<=t;i++) {
		f>>a>>b;
		if(b>a)
			swap(a,b);
		r=1;
		while(r!=0) {
			r=a%b;
			a=b;
			b=r;
			}
		g<<a<<'\n';
		}
	return 0;
}
