#include<fstream>
using namespace std;
int main(){
	int n,i,a[100000],r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;n=n*2;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=n;i=i+2){
		if(a[i]<a[i+1]) 
			r=a[i]%a[i+1];
		else r=a[i+1]%a[i];
		while(r){
			r=a[i]%a[i+1];
			a[i]=a[i+1];
			a[i+1]=r;
		}
		g<<a[i]<<endl;
	}
	return 0;
}
