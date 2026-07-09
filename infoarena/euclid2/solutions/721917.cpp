#include <fstream>
using namespace std;
inline int gcd(int a,int b)
{
	while (a!=0 && b!=0)
	{
		if(a>b) a=a%b;
		else b=b%a;
	}
	if (a==0) return b; else return a;
	
}
int main()
{
	int a,b;
	int n;
	ifstream in("euclid2.in",ios::in);
	ofstream out("euclid2.out",ios::out);
	in>>n;
	for(int i=0;i<n;i++)
	{
		in>>a>>b;
		out<<gcd(a,b)<<endl;

	}
	in.close();
	out.close();
	return 0;

}