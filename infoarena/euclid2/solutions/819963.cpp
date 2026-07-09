#include<fstream>
using namespace std;
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,r,a,b;
f >> n;
while(n)
{
	f >> a >> b;
	while(b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	g << a << endl;
    n--;
}
return 0;
f.close();
g.close();
}
