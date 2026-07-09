#include <fstream>
using namespace std;


int n, x, y;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	in >> n;
	for(int i = 0; i < n; i++)
	{
		in >> x >> y;
		while(x != y)
		{
			if(x > y)
				x -= y;
			else
				y -= x;
		}
		out << x << endl;
	}

	in.close();
	out.close();
	return 0;
}