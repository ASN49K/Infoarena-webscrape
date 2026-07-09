#include<iostream>
#include<fstream>

using namespace std;

int euclid(int a,int b)
{
	if(!b)
		return a;
	return euclid(b, a%b);
}

int main(){
int n,a,b;
ifstream intrare;
ofstream iesire;
intrare.open("euclid2.in");
intrare>>n;
iesire.open("euclid2.out");
for(int i=0;i<n;i++)
	{intrare>>a>>b;  iesire<<euclid(a,b)<<"\n"; }
intrare.close();
iesire.close();

return 0;}