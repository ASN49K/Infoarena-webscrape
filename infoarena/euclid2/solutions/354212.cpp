#include <fstream>
using namespace std;
unsigned int n;
long a,b,r;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main() {
	in>>n;
	while(n>0){in>>a>>b;
	
			   r=a%b;
	
			   while(r>0){a=b;
						  b=r;
						  r=a%b;}
			   
	out<<b<<"/n";
	
	n--;}
    return 0;
}	
