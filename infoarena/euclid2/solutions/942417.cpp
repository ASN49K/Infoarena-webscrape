#include <fstream>
#include <limits>
using namespace std;
 
ifstream in("euclid2.in");
ofstream out("euclid2.out");

long cmmdc(long a,long b);

int main()
{
    long n,a,b,c;
	in>>n;
    in.ignore(numeric_limits<streamsize>::max(),'\n');
    for(int i=0;i<n;++i)
    {
        in>>a>>b;
        in.ignore(numeric_limits<streamsize>::max(),'\n');
		c=cmmdc(a,b);
        out<<c<<"\n";
    }
    in.close();
    out.close();
    return 0;
}

long cmmdc(long a,long b)
{
	long r;
	while (b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
