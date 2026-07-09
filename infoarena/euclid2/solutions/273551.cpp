#include <fstream>
using namespace std;
ifstream cin("euclid.in");
ofstream cout("euclid.out");
int divp(int a,int b)
{
	int t;
	  while(b!=0)
	  {
         t = b;
         b = a % b;
         a = t;
	  }
	return a;
};
int main()
{
	int a,b,n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		cout<<divp(a,b)<<"\n";
	}
return 0;
}

