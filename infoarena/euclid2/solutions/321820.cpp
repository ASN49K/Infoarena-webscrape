#include "fstream"
std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");
int cmmdc ( int a,int b) 
{
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}
int main ()
{
	int a,b,t;
	in>>t;
	while(t)
	{
		
	in>>a>>b;
	out<<cmmdc(a,b)<<"\n";
	t--;
	}
	in.close ();
	out.close ();
	return 0;
}