#include<iostream>
#include<fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");



int main()
{
int t,i,a,b,k;
f>>t;
for(i=0;i<t;i++)
	{
		f>>a>>b;
		while(b!=0)
			{
				k=b;
				b=a%b;
				a=k;
			}
		g<<a<<endl;
	}
return 0;
}