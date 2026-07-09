#include<iostream.h>
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main(){
	int t,x,y,m;
	f>>t;
	for(int i=1;i<=t;i++)
	{f>>x>>y;
	while(x%y!=0)
	{m=x;
	x=y;
	y=m%y;
	}
	g<<y<<endl;
	}
	return 0;

}
	