#include<fstream>
using namespace std;
int divizor(int a,int b);
int main() {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int a,b,n;
	f>>n;
	for(int i=0;i<n;i++){
	f>>a>>b;
	g<<divizor(a,b)<<'\n';
	}
	f.close();
	g.close();
	return 0;
	}

int divizor(int a, int b){
	if(a%b==0)
		return b;
	else
		return divizor(b,a%b);
	} 