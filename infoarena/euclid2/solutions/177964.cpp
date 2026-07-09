#include <fstream.h>

int cmmdc(int a, int b)
{
	if(b==0) return a;
	return cmmdc(b, a%b);
}


int main(){
	int t, a, b;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>t;
	while(t--)
		{
			fin>>a>>b;
			fout<<cmmdc(a,b)<<"\n";
}
return 0;
}
