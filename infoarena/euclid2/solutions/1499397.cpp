#include<iostream>
#include<fstream>

using namespace std;

void euclid(int a,int b, int *d)
{
	if(b==0)
		*d=a;
	else euclid(b, a%b, d);
}

int main(){
int n,a,b;
ifstream intrare;
ofstream iesire;
intrare.open("euclid2.in");
intrare>>n;
iesire.open("euclid2.out");
for(int i=0;i<n;i++)
	{intrare>>a>>b; int r=0; euclid(a,b,r); iesire<<r<<"\n";}
intrare.close();
iesire.close();

return 0;}