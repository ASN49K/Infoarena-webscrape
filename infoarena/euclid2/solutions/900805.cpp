#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,x,y,i;
int euclid(int a,int b){
	int c;
	while(b)
	{c=a%b;
	a=b;
	b=c;
	}
	return a;
}
int main(){
	f>>t;
	for(i=1;i<=t;i++)
	{f>>x>>y;
	g<<euclid(x,y)<<endl;
	}
	return 0;
}
	