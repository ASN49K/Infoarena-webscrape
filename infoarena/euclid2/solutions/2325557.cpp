#include <fstream>
	
int main(){
		ifstream f euclid2.in;
	ofstream g euclid2.out;
	int a,b,c,n;
	f>>n;
	for(int i=1;i<=n;i++)
	{
		f>>a>>b;
		while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    g<<a<<endl;
	}
	
	return 0;
}
