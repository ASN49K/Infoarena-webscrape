#include<fstream>
using namespace std;
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,r,a,b;
f >> n;
for(i = 0; i < n; i++)
{
	f >> a >> b;
	while(b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	g << a << endl;
}
return 0;
f.close();
g.close();

}
