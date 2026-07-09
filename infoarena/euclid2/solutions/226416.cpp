#include<fstream>
using namespace std;
int main()
{
	int a, b, r, i, T;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>T;
		for(i=1; i<=T; i++)
		{
			in>>a>>b;
			while(a%b)
			{
				r=a%b;
				a=b;
				b=r;
			}
			out<<b<<"\n";
		}
in.close();
out.close();
return 0;
}