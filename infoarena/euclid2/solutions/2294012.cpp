#include<iostream>
#include<fstream>

using namespace std;
ifstream f("input.in");
ofstream g("output.out");
int main() {
  int a,b,c,d,e=1;
  f>>a;
  for(int i=1;i<=a;++i){

  	f>>b>>c;
  	while(c){
  		d=b%c;
  		b=c;
  		c=d;
  	}
  	g<<b;
  	if(e<a)
  	{
  		g<<"\n";
  		++e;
  	}
  }
  return 0;
}
