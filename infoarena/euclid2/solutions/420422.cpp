

using namespace std;
#include<fstream>
ifstream f("euclid2.in");
ofstream g("euclid2.out");

	

int main()
{ int n,i,a,b,r;
f>>n;
for(i=0;i<n;i++)
{ 
f>>a;f>>b;
r=a%b;
while(r!=0)
{
	a=b;b=r;r=a%b;
}
g<<b;
g<<endl;
}
return 0;
}
