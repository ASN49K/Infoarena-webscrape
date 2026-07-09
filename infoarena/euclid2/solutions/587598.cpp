#include<fstream>
using namespace std;
int divizor(int a, int b)
{
	if (!b) return a;
  return divizor(b, a % b);
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t,a,b;
	f>>t;
	while(t)
	{
		f>>a;
		f>>b;
		g<<divizor(a,b)<<endl;
		t--;
	}
	f.close();
	g.close();
	return 0;
}