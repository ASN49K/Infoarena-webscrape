#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int divi(int a, int b){
	int r;
	while (a%b){
		r=a%b;
		a=b;
		b=r;
	}
	return r;
}
int main()
{
	int a, b, n, i;
	cin>>n;
	for (i=1;i<=n;i++){
		cin>>a>>b;
		cout<<divi(a,b);
	}
	cin.close();
	cout.close();
	return 0;
}