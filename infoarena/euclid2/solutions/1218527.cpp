#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Math
{
public:
	static int euclid(int a , int b);
};

int Math::euclid(int a , int b)
{
	int r;

	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int n , a , b;

	in >> n;

	for(int i = 0 ; i < n ; i++)
	{
		in >> a >> b;
		out << Math::euclid(a , b) << '\n';
	}

	in.close();
	out.close();
	return 0;
}
