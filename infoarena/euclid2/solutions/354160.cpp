#include <fstream>
using namespace std;
unsigned int a,b,r,i;
ifstream in("cmmdc.in");
ofstream out("cmmdc.out");
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
		
		if(b==1) b=0;
		out<<b<<"\n";
		i--;
	}
	return 0;
}
