#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// --- basics
#define int32 int
#define int64 int long long
#define	uint32 unsigned int32
#define uint64 unsigned int64

// --- prototypes
uint32 gcd(uint32 a, uint32 b);

/// --- input/output files
#define INPUT_FILE	"euclid2.in"
#define	OUTPUT_FILE	"euclid2.out"

int main()
{
	freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w", stdout);

	uint32 N;
	scanf("%u", &N);

	uint32 a, b;
	for (uint32 i = 0; i < N; i++)
	{
		scanf("%u %u", &a, &b);
		printf("%u\n", gcd(a, b));
	}

	return 0;
}

// --- functions
uint32 gcd(uint32 a, uint32 b)
{
	uint32 r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}