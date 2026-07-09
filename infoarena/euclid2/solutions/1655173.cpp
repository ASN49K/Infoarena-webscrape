#include <fstream>
using namespace std;

long long gcd(long long a,long long b)
{
    if (b == 0)
       return a; 
    else
       return gcd(b, a % b);
}

int main()
{
	ifstream q("euclid2.in");
	ofstream w("euclid2.out");
	long long t,x,y;
	q >> t ;
	for (long long i=1; i<=t; i++)
	{
		q >> x >> y;
		w << gcd(x,y) << endl;
	}
	q.close();
	w.close();
	return 0;
}