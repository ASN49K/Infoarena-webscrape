#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream f1("euclid.in");
ofstream f2("euclid.out");
int x,t,r,i;
f1>>t;
long a,b;
for(i=1;i<=t;i++)
{f1>>a>>b;
if(b>a) 
{x=b;
b=a;
a=x;
}
r=a%b;
cout<<a<<" "<<b<<" ";
while(r)
{a=b;
b=r;
r=a%b;
}
f2<<b<<endl;
}
	

return 0;
}
