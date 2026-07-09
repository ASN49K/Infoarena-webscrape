#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main(){
	int t,x,y,m;
	f>>t;
	for(int i=1;i<=t;i++)
	{f>>x>>y;
	while(y!=0)
	{m=x%y;
	x=y;
	y=m;
	}
	g<<x<<endl;
	}
	return 0;

}
	