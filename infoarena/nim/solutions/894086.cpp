#include<fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
	int n, x, i, t, j, nr;
	in >> t;
	for(i=1;i<=t;i++)
	{
		in >> n;
		x=0;
		for(j=1;j<=n;j++)
		{
			in >> nr;
			x=x^nr;
		}
		if(x)
			out << "DA";
		else
			out << "NU";
		out << "\n";
	}
	in.close();
	out.close();
	return 0;
}
