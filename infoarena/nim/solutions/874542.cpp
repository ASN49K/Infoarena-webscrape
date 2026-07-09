#include <fstream>
using namespace std;

ifstream fi("nim.in");
ofstream fo("nim.out");

long t,i,sum,x,n;

int main(){
	
	fi >> t;
	
	while (t--){
		fi >> n; sum=0;
		for (i=1; i<=n; i++) fi >> x, sum=sum ^ x;
		if (sum) fo << "DA\n"; else fo << "NU\n";
	}
	
	return 0;
}
