#include<fstream>
using namespace std;
int main(){
	int t,r,i;
	unsigned long a[10000],b[10000];
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=0;i<t;i++){
		f>>a[i]>>b[i];
		do{
			r=a[i]%b[i];
			a[i]=b[i];
			b[i]=r;
		}while(r);
		g<<a[i]<<endl;
	}
	return 0;
}
	