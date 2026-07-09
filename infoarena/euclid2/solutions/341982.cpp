#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int cmmdc(int a,int b) {
	if (b == 0) return a;
	return cmmdc(b,a % b);
}

int main() {
	ios::sync_with_stdio(false);
	
	//ifstream fin("euclid2.in");
	//ofstream fout("euclid2.out");

	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	long T;
	int a,b;
	scanf("%ld",&T);
	for (long t = 0;t < T;++t) 
	{
	scanf("%d%d",&a,&b);
	int c = cmmdc(a,b);
	//if (c == 1) fout << 0 << endl;
	printf("%d\n",c);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
