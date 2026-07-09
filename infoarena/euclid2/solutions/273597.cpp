#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int a, int b){  
 int r;  
 r=a%b;  
while(r!=0){  
 a=b;  
 b=r;  
r=a%b;}  
return b;}  
int main()
{	
	int n,a,b,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		cout<<euclid(a,b)<<"\n";
	}
return 0;
}


