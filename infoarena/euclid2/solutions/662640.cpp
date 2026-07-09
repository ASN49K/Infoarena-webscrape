// http://infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int first,int second);

int main()
{
	int count,first,second;

	in >> count;
	for(int i=1;i<=count;i++)
	{
		in >> first >> second;
		out << cmmdc(first,second) << "\n";
	}

	in.close();
	out.close();

	return (0);
}

int cmmdc(int first,int second)
{
	if(second)
		return cmmdc(second,first % second);
	else
		return first;
}
