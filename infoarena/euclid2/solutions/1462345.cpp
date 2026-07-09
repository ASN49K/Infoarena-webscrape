#include <cstdio>

#define uint unsigned int

#define	input_file	"euclid2.in"
#define	output_file	"euclid2.out"

using namespace std;

uint Gcd(uint a, uint b)
{
	uint r = a % b;
	while(r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	
	return b;
}

int main()
{
	freopen(input_file, "r", stdin);
	freopen(output_file, "w", stdout);
	
	uint T; scanf("%u", &T);
	for(int i = 0; i < T; i++)
	{
		uint a, b;
		scanf("%u %u", &a, &b);
		
		printf("%u\n", Gcd(a, b));
	}
	
	return 0;
}