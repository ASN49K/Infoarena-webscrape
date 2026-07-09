#include<fstream.h>

using namespace std;

int main()

{unsigned long long t, a, i, b, r;
ifstream f("euclid2.in");
ofstream h("euclid2.out");
f>>t;
for (i=1; i<=t; i++)
{f>>a;
f>>b;
do
{r=a%b;
a=b;
b=r;}
while (r!=0);
h<<a<<'\n';}
	f.close();
	h.close();
	return 0;
}