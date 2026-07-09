#include<fstream>
using namespace std;
int main()
{int i,N,a,b,r;
ifstream f("euclid2.in");
	ofstream h("euclid2.out");
	f>>N;
	for(i=1;i<=N;i++)
	{f>>a>>b;
	do
	{r=a%b;
	a=b;
	b=r;}
	while(b!=0);}
	h<<a;
	f.close();
	h.close();
	return 0;}