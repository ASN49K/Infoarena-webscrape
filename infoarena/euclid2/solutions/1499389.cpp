#include<iostream>
#include<fstream>

using namespace std;

int euclid(int a,int b)
{
while(a!=b)
	if(a>b)
		a-=b;
	else b-=a;
return a;}

int main(){
int n,a,b;
ifstream intrare;
ofstream iesire;
intrare.open("euclid2.in");
intrare>>n;
iesire.open("euclid2.out");
for(int i=0;i<n;i++)
	{intrare>>a>>b; iesire<<euclid(a,b);}
intrare.close();
iesire.close();

return 0;}