#include <fstream>

int cmmdc(int a , int b)
{
	int r;

	while(b != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	int n , a , b , c;
	std::fstream in,out;

	in.open("euclid2.in",std::ios::in);
	out.open("euclid2.out",std::ios::out);
	in >> n;

	while(n)
	{
		in >> a >> b;
		c = cmmdc(a , b);
		out << c << '\n';
		n--;
	}

	in.close();
	out.close();
	return 0;
}