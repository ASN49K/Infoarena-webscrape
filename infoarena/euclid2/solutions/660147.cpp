#include<fstream>
using namespace std;

long int cmmdc(long int a, long int b) {
    if (a<b) {
		a+=b;
		b=a-b;
		a=a-b;
		}
    do {
        a%=b;
		if (!a)
           return b;
        b%=a;
        }
	while (a!=0 && b!=0);
    return a;
}

int main() {
    long int x,y;
    int n,i;
    ifstream f("euclid2.in",ifstream::in);
    ofstream g("euclid2.out",ifstream::out);
    f>>n;
    for (i=0;i<n;i++) {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
        }
    return 0;
}
