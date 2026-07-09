#include <fstream>
using namespace std;
ifstream cin("euclid.in");
ofstream cout("euclid.out");
void divp(int a,int b)
{
	int t;
	  while(b!=0)
	  {
         t = a%b;
         a=b;
         b=t;
	  }
	  cout<<a<<"\n";
};
int main()
{
	int a,b,n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		divp(a,b);
	}
return 0;
}

