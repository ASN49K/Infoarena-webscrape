#include<iostream>
#include<fstream>
using namespace std;
int main()
{int T,i=0,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
while(i<T){
	f>>a>>b;
	while(a!=b){
		if(a>b)
			a=a-b;
		else b=b-a;
	}
g<<b<<endl;	
	i++;
}
g.close();
}
