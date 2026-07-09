#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
unsigned int n,a,b;
void programx(unsigned int x, unsigned int y)
{
	unsigned int div=1;
	for(unsigned int d=2;d<=a;d++)if(a%d==0 && b%d==0)div=d;
	out<<div<<endl;
}
int main()
{
	in>>n;
	for(unsigned int i=1;i<=n;i++){in>>a>>b;
	                               programx(a,b);}
    return 0;
}	
