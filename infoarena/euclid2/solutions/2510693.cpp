#include <fstream>
using namespace std;
int main(int arg, char *argv[]) {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	long long int n,a,b;
	in>>n;
	for(long long int i=1;i<=n;i++){
		in>>a>>b;
		long long int r=a%b;
		while(r){
			a=b;
			b=r;
			r=a%b;
		}
		out<<b<<endl;
	}
}