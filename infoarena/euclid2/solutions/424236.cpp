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
		do{
			r=a[i]%a[i+1];
			a[i]=a[i+1];
			a[i+1]=r;
		}while(r);
		g<<a[i]<<endl;
	}
	return 0;
}
