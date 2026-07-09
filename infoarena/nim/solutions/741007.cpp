#include<fstream>

using namespace std;

int main()
{
	ifstream in("nim.in");
	ofstream out("nim.out");
	int t, nr, suma, a;
	in>>t;
	while(t--)
	{
		in>>nr;
		in>>suma;
		for(int i = 1; i < nr; i++)
		{
			in>>a; 
			suma ^= a;
		}
		if(suma)
			out<<"DA\n";
		else
			out<<"NU\n";
	}
	in.close();
	out.close();
}