#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int a, int b){  
 int r;  
while(b!=0){  
   r=a%b;
	a=b;  
   b=r;  
}  
return a;}  
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


