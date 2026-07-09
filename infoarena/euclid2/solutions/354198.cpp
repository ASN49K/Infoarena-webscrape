#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
unsigned int n,a,b;
int main()
{
	in>>n;
	for(unsigned int i=1;i<=n;i++){in>>a>>b;
	                               unsigned int r=0;
    r=a%b;
	while(r>0){a=b;
	            b=r;
	            r=a%b;}
	out<<b<<endl;}
    return 0;
}	
