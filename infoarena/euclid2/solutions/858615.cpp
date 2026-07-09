#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	long n, a, b, f, i;
	in >> n;
	for(i=1;i<=n;i++)
	{
		in >> a >> b;
		while(b)
		{
			f=a%b;
			a=b;
			b=f;
		}
		out << a << "\n";
	}
	in.close();
	out.close();
	return 0;
}
		