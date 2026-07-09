#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
unsigned int n,a,b;
void programx(unsigned int x, unsigned int y)
{
	unsigned int r=0;
    r=x%y;
	while(r!=0){x=y;
	            y=r;
	            r=x%y;}
	out<<y<<endl;
}
int main()
{
	in>>n;
	for(unsigned int i=1;i<=n;i++){in>>a>>b;
	                               programx(a,b);}
    return 0;
}	
