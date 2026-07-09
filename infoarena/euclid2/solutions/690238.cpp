#include <iostream>
#include <fstream>

using namespace std;

long cmmdc(long a, long b)
{
	if(!b) return a;
	
	return cmmdc(b, a % b);
}

int main()
{

	int T, i;
	
	long a, b;
	
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%d", &T);
	
	for(i=1;i<=T;++i)
	{
		scanf("%ld %ld", &a, &b);
		
		printf("%ld\n", cmmdc(a, b));
	}
	
	fclose(stdin);
	
	fclose(stdout);
	
	return 0;

}