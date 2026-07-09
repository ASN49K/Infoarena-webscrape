#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i;
long long a,b,c; 
int main()
{
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		while (b) 
	{
        c = a % b;
        a = b;
        b = c;
    }
    g<<a<<'\n';
	}
	return 0;
}

