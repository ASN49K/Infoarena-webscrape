#include<fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	int n, a, b;
	in >> n;
	while(n)
	{
		in >> a >> b;
		while(a!=b)
		{
			if(a>b)
				a-=b;
			else
				b-=a;
		}
		out << a <<"\n";
		n--;
	}
	return 0;
	in.close();
	out.close();
}
		