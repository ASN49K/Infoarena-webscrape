#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
	if(b==0) return a;
	return cmmdc(b, a%b);
}
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n, a, b;
int main()
{  
	in>>n;
	while(n)
	{
		in>>a>>b;
		out<<cmmdc(a,b)<<"\n";
		n--;
	}
	return 0;
}
