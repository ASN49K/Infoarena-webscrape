#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
FILE *f1, *f2;
long int t,a,b;
long int cmmdc(long int nr1,long int nr2)
{
	if((nr1 + nr2) == 0) return 0;
	if((nr1*nr2) == 0) return nr1+nr2;
	while(nr1!=nr2)
	{
		if(nr1>nr2)nr1-=nr2;
		else nr2-=nr1;
	}
	return nr1;
}
int main()
{
	f1 = freopen("euclid2.in", "r", stdin);
	f2 = freopen("euclid2.out", "w", stdout);
	scanf("%li", &t);
	for(;0<t;t--)
	{
		scanf("%li %li", &a,&b);
		printf("%li\n", cmmdc(abs(a),abs(b)));
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
