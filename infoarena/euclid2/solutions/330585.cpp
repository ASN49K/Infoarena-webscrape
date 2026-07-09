#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b)
{
	int r;
	while(b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int T,a,b;
	in>>T;
	while (T--)
	{
		in>>a>>b;
		a=cmmdc(a,b);
		out<<a<<"\n";
	}
	in.close();
	out.close();
	return 0;
}
