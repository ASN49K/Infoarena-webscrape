#include <fstream>
#include <string>
using namespace std;

int main ()
{
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	int n, a, b, r;
	in>>n;
	while(n--){
		in>>a>>b;
		while(b){
			r=a%b;
			a=b;
			b=r;}
		out<<a<<'\n';}
	return 0;
}

