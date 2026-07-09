#include<iostream>
#include<fstream>
using namespace std;
int main()
{unsigned T,i=0,a,b,c;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
while(i<T){
	f>>a>>b;
	while(b){
	c=a%b;
	a=b;
	b=c;
	}
g<<a<<endl;	
	i++;
}
f.close();
g.close();
}
