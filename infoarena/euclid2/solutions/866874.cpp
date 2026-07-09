#include<iostream>
#include<fstream>
using namespace std;
int T,i,a,r,b;
int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<endl;
		
	}
	f.close();
	g.close();
	return 0;
}