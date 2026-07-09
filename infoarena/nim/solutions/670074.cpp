//#include<iostream>
#include<fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int n,t,a,sum,i;
int main()
{
	in>>t;
	while(t--){
		in>>n;
		sum=0;
		for(i=1;i<=n;i++){
			in>>a;
			sum=sum^a;
		}
		if(sum) out<<"DA\n";
		else out<<"NU\n";
	}
	return 0;
}