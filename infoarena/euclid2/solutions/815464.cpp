#include<fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	int n, a, b, p;
	in >> n;
	while(n)
	{
		in >> a >> b;
		while(b)
		{
			p=a%b;
			a=b;
			b=p;
		}
		out << a <<"\n";
		n--;
	}
	return 0;
	in.close();
	out.close();
}
		