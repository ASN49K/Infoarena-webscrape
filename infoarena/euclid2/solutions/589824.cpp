#include<fstream>
using namespace std;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,a,b,j;
f>>t;
for(i=1;i<=t;i++)
{	f>>a>>b;
while(b!=0)
{j=a%b;
a=b;
b=j;}
g<<a<<endl;
}
}
	