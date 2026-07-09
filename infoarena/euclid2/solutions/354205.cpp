#include <fstream>
using namespace std;
unsigned int i;
long a,b,r;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main() {
	in>>i;
	while(i>0){
		in>>a>>b;
		
		r=a%b;
		while(r>0) {
			   a=b;
			   b=r;
			   r=a%b;
		}
		
		out<<b<<"\n";
		i--;
	}
	return 0;
}
