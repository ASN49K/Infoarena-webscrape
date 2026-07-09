#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int fun(int a ,int b)
{
    if(b==0)
        return a;
    else
        return fun(b,a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int i,a,b,t;
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		g<<fun(a,b);
	}
	return 0;
}