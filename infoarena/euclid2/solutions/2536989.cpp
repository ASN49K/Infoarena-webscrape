#include <iostream>
#include <cstdio>

using namespace std;

int cmmdc(int a, int b){
	int r;
	while(a%b){
		r = a%b;
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	FILE *fin, *fout;
	int n,a,b,ans;
	fin = fopen("euclid2.in","r");
	fout = fopen("euclid2.out","w");
	fscanf(fin,"%d",&n);
	while(n--){
		fscanf(fin,"%d %d",&a,&b);
		ans = cmmdc(a, b);
		fprintf(fout,"%d\n",ans);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
