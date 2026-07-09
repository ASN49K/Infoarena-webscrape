#include <fstream>
using namespace std;
ifstream cin("euclid.in");
ofstream cout("euclid.out");
void divp(int a,int b)
{
	int s,i,max;
	max=0;
	for(i=1;i*i<=a;i++)	
		if(a%i==0)
		{
			s=a/i;
			if(b%i==0)
				if(i>max)
					max=i;
			if(b%s==0)
				if(s>max)
					max=s;
		}
	cout<<max<<"\n";
};
int main()
{
	int a,b,n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		if(a<=b)
			divp(a,b);
		if(a>b)
			divp(b,a);
	}
return 0;
}

