#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream f1("euclid2.in");
ofstream f2("euclid2.out");
int x,t,r,i;
f1>>t;
long a,b;
for(i=1;i<=t;i++)
{f1>>a>>b;
a=max(a,b);
b=min(a,b);
r=a%b;
while(r)
{a=b;
b=r;
r=a%b;
}
f2<<b<<endl;
}
	

return 0;
}
