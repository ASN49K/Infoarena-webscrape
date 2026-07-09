#include<fstream>
using namespace std;
int main () 
{     
	ifstream cin("euclid2.in");     
	ofstream cout("euclid2.out");    
	int a,b,i,t,r,c,d;    
	cin>>t;   
	for(i=1;i<=t;i++)        
	{     
		cin>>a>>b;    
		c=a;d=b;
		while(a%b!=0){r=a%b;a=b;b=r;} 
		while(c%d==0){c=c/d;r=d;} 
		cout<<r<<'\n'; 
	} 
	return 0; 
}
