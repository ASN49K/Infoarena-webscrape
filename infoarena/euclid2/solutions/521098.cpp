#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream f1("euclid2.in");
ofstream f2("euclid2.out");
int x,t,d,i;
f1>>t;
long a,b;
for(i=1;i<=t;i++)
{f1>>a>>b;
x=1;
for(d=1;d<=min(a,b);d++)
	if((a%d==0)&&(b%d==0)) x=d;
	
	
f2<<x<<" ";

}
	

return 0;
}
