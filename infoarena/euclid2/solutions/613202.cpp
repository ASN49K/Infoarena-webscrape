#include <fstream>
using namespace std;

ifstream in("euclid.in");
ofstream out("euclid.out");

int n;

int euclid(int a, int b);

int main() 
{
int i1, a, b;

in>>n;
for(i1=0;i1<n;i1++) 
	{
	in>>a>>b;
	out<<euclid(a, b)<<'\n';	
	}

in.close();
out.close();
return 0;
}

int euclid(int a, int b) 
{
int r;
r = a%b;
while(r)
	{
	a = b;
	b = r;
	r = a%b;
	}
return b;
}
