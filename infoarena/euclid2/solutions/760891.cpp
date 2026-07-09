#include<iostream>
#include<fstream>
using namespace std;
int main()
{int r,a,t,b;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
f>>t;
for (int i=1;i<=t;i++)
	{f>>a>>b;
do
{r=a%b;
a=b;
b=r;}
while (r!=0);
	g<<a<<endl;}
return 0;}
