#include<iostream>
#include<fstream>
using namespace std;
int euclid(int a,int b)
{int c;
if(b>a){c=a;
a=b;
b=c;}
c=b%a;
	while(c!=0)
	
{c=a%b;
a=b;
b=c;

}


return a;
}
int main()
{int i,n,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
{f>>a>>b;g<<euclid(a,b)<<endl;}
f.close();g.close();
}
