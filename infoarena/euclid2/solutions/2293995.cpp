#include<iostream>
#include<fstream>

using namespace std;

int euclid(int x,int y){
	int z;
	while(y)
	{
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}

ifstream f("input.in");
ofstream g("output.out");
int main() {
  int a,b,c;
  f>>a;
  for(int i=1;i<=a;++i){

  	f>>b>>c;

  	g<<euclid(b,c)<<"\n";
  }
  return 0;
}
