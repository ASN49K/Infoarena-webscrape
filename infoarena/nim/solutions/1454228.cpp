#include <iostream>
#include <fstream>
#include <assert.h>

const char IN[] = "nim.in", OUT[] = "nim.out";

using namespace std;

int T;

inline void read_data() {
	assert(freopen(IN, "r", stdin));
	assert(freopen(OUT, "w", stdout));
	int N;
	assert(scanf("%d", &T));
	for (int test = 1; test <= T; ++test) {
		assert(scanf("%d", &N));
		int s = 0;
		for (int i = 1; i <= N; ++i) {
			int x;
			assert(scanf("%d", &x));
			s ^= x;
		}
		if (s) printf("DA\n");
		else printf("NU\n");
	}
	fclose(stdout);
	fclose(stdin);
}

int main() {
	read_data();
	return 0;
}