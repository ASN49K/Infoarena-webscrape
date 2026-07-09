#include<fstream.h>

using namespace std;

int main()

{unsigned long long t, a[100000], i, b[100000], r;
ifstream f("euclid2.in");
ofstream h("euclid2.out");
f>>t;
for (i=1; i<=t; i++)
	f>>a[i]>>b[i];
for (i=1; i<=t; i++)
	{do
	{r=a[i]%b[i];
	a[i]=b[i];
	b[i]=r;}
	while (r!=0);
	h<<a[i]<<'\n';
	}
	
	f.close();
	h.close();
	return 0;
}